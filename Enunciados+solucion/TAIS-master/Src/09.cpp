#include <iostream>
#include <fstream>
#include "Grafo.h"
#include <vector>


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
bool arbolLibre(Grafo g) {

	DepthFirstSearch pru(g, 0);

	if (pru.count() == g.V() && (g.V() > g.E())) {
		return true;
	}
	else {
		return false;
	}



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

		libre = arbolLibre(g);
		
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