/*
* Milagros del Rocío Peña Quineche
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

#include "TreeMap_AVL.h"

map<int, bool> leerArbol(int nClaves) {
	int clave;
	map<int, bool> treemap = map<int, bool>();

	for (int i = 0; i < nClaves; i++) {
		std::cin >> clave;
		treemap.insert(clave);
	}
	
	return treemap;
}

//El coste es logarítmico en el nº de nodos
vector<long int> resuelve(map<int, bool> &treemap, int k1, int k2) {
	vector<long int> v = vector<long int>();

	v = treemap.rango(k1, k2);

	return v;
}

void resuelveCasos(map<int, bool> &treemap, int k1, int k2) {
	vector<long int> v = resuelve(treemap, k1, k2);

	if (v.size() != 0) {
		vector<long int>::const_iterator cit = v.begin();

		cout << *cit;
		++cit;
		while (cit != v.end()) {
			cout << " " << *cit;
			++cit;
		}
		cout << endl;
	}
	else {
		cout << endl;
	}
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int claves;
	cin >> claves;
	while (claves != 0) {
		map<int, bool> treemap = leerArbol(claves);
		int k1, k2;
		cin >> k1 >> k2;
		resuelveCasos(treemap, k1, k2);

		cin >> claves;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}