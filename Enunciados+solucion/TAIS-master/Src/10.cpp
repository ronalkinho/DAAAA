#include <iostream>
#include <fstream>
#include "Grafo.h"
#include <vector>
#include "Bipartito.h"


using namespace std;

//Lineal en el número de aristas del grafo
void poneArista(Grafo &g, int a) {

	int v1, v2;

	for (int i = 0; i < a; i++) {

		cin >> v1;
		cin >> v2;

		g.ponArista(v1, v2);

	}

}

//Lineal en el número de vertices del grafo
bool arbolBipartito(Grafo g) {

	Bipartito bi(g);

	return bi.esBipartito();
}

bool resuelveCaso() {
	
	int v = 0;
	int a;
	bool libre = true;

	cin >> v;

	if (v == 0) return false;
	else {

		Grafo g(v);

		cin >> a;

		poneArista(g, a);

		libre = arbolBipartito(g);
		
	}

	if (libre) {
		cout << "SI" << endl;
	}
	else
		cout << "NO" << endl;
	

	return true;
	
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {};

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}