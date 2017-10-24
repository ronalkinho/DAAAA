
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"
using namespace std;

const int INF = 1e9;

void relax(AristaDirigida<int> e, IndexPQ<int> & pq, vector<int> carga, vector<int> timeTo)
{
	int v = e.from(), w = e.to();
	if (timeTo[w] > timeTo[v] + carga[w] + e.valor()){
		timeTo[w] = timeTo[v] + carga[w] + e.valor();
		pq.update(w, timeTo[w]);
	}
}

// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N, tmp, enlaces, v1, v2, valor;
	cin >> N;

	if (N == 0) // no hay más casos
		return false;

	// si no hay centinela
	// if (!cin)
	//    return false;
	vector<int> tmpPag(N, INF);
	vector<int> carga(N);
	IndexPQ<int> pq(N);
	GrafoDirigidoValorado<int> g(N);

	for (int i = 0; i < N; ++i){
		cin >> tmp;
		carga[i] = tmp;
	}
	tmpPag[0] = carga[0];

	cin >> enlaces;
	for (int i = 0; i < enlaces; ++i){
		cin >> v1 >> v2 >> valor;
		AristaDirigida<int> e(v1 - 1, v2 - 1, valor);
		g.ponArista(e);
	}
	// leer resto del caso

	// resolver caso
	pq.push(0, tmpPag[0]);
	while (!pq.empty())
	{
		int v = pq.top().elem;
		for (AristaDirigida<int> e : g.adj(v))
			relax(e, pq, carga, tmpPag);
		pq.pop();
	}
	
	if (tmpPag[N - 1] == INF)
		cout << "IMPOSIBLE" << endl;
	else
		cout << tmpPag[N - 1] << endl;
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
