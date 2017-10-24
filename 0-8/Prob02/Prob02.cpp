/*
* Milagros del Rocío Peña Quineche
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;

// lee un árbol binario de la entrada estándar

bintree<int> leerArbol() {
	int raiz;
	std::cin >> raiz;
	if (raiz == -1) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}

//Complejidad lineal en el nº de nodos
int estaEquilibrado(bintree<int> const &ra) {
	int alt = 0;

	if (!ra.empty()) {
		int altIzq = estaEquilibrado(ra.left());
		int altDr = estaEquilibrado(ra.right());

		if (altIzq == -1 || altDr == -1 || abs(altIzq - altDr) > 1)
			alt = -1;
		else
			alt = max(altIzq, altDr) + 1;
	}

	return alt;
}

//Complejidad lineal en el nº de nodos
bool estaOrdenado(bintree<int> const &ra) {
	bool ok = true;
	if (!ra.empty()) {
		bintree<int>::const_iterator cit = ra.begin();

		int elem = *cit;
		++cit;
		while (cit != ra.end() && ok) {
			if (*cit <= elem) {
				ok = false;
			}
			elem = *cit;
			++cit;
		}
	}

	return ok;
}


// resuelve un caso de prueba
void resuelveCaso() {
	auto arbol = leerArbol();
	if (estaEquilibrado(arbol) != -1 && estaOrdenado(arbol))
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
}



int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}






