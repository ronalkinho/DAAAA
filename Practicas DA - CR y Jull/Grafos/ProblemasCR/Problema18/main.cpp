#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include "PriorityQueue.h"
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

using namespace std;

const int INF = 1e9;

void relax(AristaDirigida<int> e, IndexPQ<int> & pq, int *timeTo)
{
	int v = e.from(), w = e.to();
	if (timeTo[w] > timeTo[v] + e.valor()) {
		timeTo[w] = timeTo[v] + e.valor();
		pq.update(w, timeTo[w]);
	}
}

void reparto(int casas, int caminos) {
	int *timeTo, *timeFrom, i, *destino, c1, c2, cost, oficina, paquetes, v, esfuerzo = 0;
	IndexPQ<int> pq(casas), pq1(casas);
	GrafoDirigidoValorado<int> pueblo(casas);
	bool imposible = false;

	for (i = 0; i < caminos; i++) {
		cin >> c1 >> c2 >> cost;
		AristaDirigida<int> e(c1 - 1, c2 - 1, cost);
		pueblo.ponArista(e);
	}

	cin >> oficina >> paquetes;
	oficina--;
	destino = new int[paquetes];

	for (i = 0; i < paquetes; i++) {
		cin >> c1;
		destino[i] = c1 - 1;
	}

	timeTo = new int[casas];
	timeFrom = new int[casas];

	timeTo[oficina] = 0;
	timeFrom[oficina] = 0;
	for (i = 0; i < casas; i++) {
		if (i != oficina) {
			timeTo[i] = INF;
			timeFrom[i] = INF;
		}
	}
	
	//Dijstra para calcular lo que tarde desde la oficina a los pueblos (timeTo)
	pq.push(oficina, timeTo[oficina]);
	while (!pq.empty()) {
		v = pq.top().elem;
		pq.pop();
		for (AristaDirigida<int> e : pueblo.adj(v))
			relax(e, pq, timeTo);
	}
	
	//Dijstra para calcular lo que tarde desde todos los destinos hasta la oficina (timeFrom)
	//para ello invierto el grafo, por lo que ahora en vez de guardar las distancias desde el
	//origen a todos los destinos se guardan las distancias desde todos los vertices al origen
	pueblo = pueblo.reverse();
	pq1.push(oficina, timeFrom[oficina]);
	while (!pq1.empty()) {
		v = pq1.top().elem;
		pq1.pop();
		for (AristaDirigida<int> e : pueblo.adj(v))
			relax(e, pq1, timeFrom);
	}

	i = 0;
	while (i < paquetes && !imposible) {	
		imposible = imposible || (timeTo[destino[i]] == INF) || (timeFrom[destino[i]] == INF);
		esfuerzo += timeTo[destino[i]] + timeFrom[destino[i]];
		++i;
	}

	if (imposible)
		cout << "IMPOSIBLE" << endl;
	else
		cout << esfuerzo << endl;

	delete[] timeFrom;
	delete[] timeTo;
	delete[] destino;
}

bool resuelveCaso() {
	int casas, caminos;

	cin >> casas >> caminos;

	if (!cin)
		return false;

	reparto(casas, caminos);

	return true;
}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}