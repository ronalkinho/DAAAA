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

typedef struct {
	int ini;
	int fin;
}t_Conf;

bool operator <(t_Conf a, t_Conf b) {
	return a.ini < b.ini;
}

void resuelveCaso(int conf) {
	PriorityQueue<t_Conf> conferencias;
	int salas=1, act, ant;

	for (int i = 0; i < conf; i++){
		t_Conf c;
		cin >> c.ini >> c.fin;
		conferencias.push(c);
	}

	ant = conferencias.top().ini;
	act = conferencias.top().fin;
	conferencias.pop();
	for (int i = 1; i < conf; i++) {
		if (conferencias.top().ini < act && conferencias.top().ini < ant) {
			salas++;
		}
		ant = max(act, conferencias.top().ini);
		act = conferencias.top().fin;
		conferencias.pop();
	}
	
	cout << salas << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int conf;
	cin >> conf;
	while(conf != 0){
		resuelveCaso(conf);
		cin >> conf;
	} 

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}