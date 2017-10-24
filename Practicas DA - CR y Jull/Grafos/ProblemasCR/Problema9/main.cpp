#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include "ConjuntosDisjuntos.h"

using namespace std;

void libre(int vertices, int aristas) {
	ConjuntosDisjuntos grafo(vertices);
	int v1, v2, i=0, j, w, numGrupos = 0, grupo = 0;
	bool fallo = false;

	for (int i = 0; i < aristas; ++i) {
		cin >> v1 >> v2;
		j = grafo.buscar(v1);
		w = grafo.buscar(v2);
		if(!fallo)
			fallo = j == w;
		grafo.unir(v1, v2);
	}

	if (!fallo) {
		grupo = grafo.buscar(0);
		j = 1;
		while (j < vertices && !fallo) {
			w = grafo.buscar(j);
			fallo = !(grupo == w);
			++j;
		}
		if (!fallo)
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

bool resuelveCaso() {
	int vertices, aristas;

	cin >> vertices >> aristas;

	if (!cin)
		return false;

	libre(vertices, aristas);

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