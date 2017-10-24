/*
* Milagros del Rocío Peña Quineche
*/
#include <iostream>
#include "bintree_eda.h"
using namespace std;

bintree<char> leerArbol() {
	char raiz;
	std::cin >> raiz;
	if (raiz == '.') { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}

//Coste lineal en nº de nodos
int estaEquilibrado(bintree<char> const ra) {
	int alt = 0;

	if(!ra.empty()) {
		int altIzq = estaEquilibrado(ra.left());
		int altDr = estaEquilibrado(ra.right());

		if (altIzq == -1 || altDr == -1 || abs(altIzq - altDr) > 1)
			alt = -1;
		else
			alt = max(altIzq, altDr) + 1;
	}

	return alt;
}

// resuelve un caso de prueba
void resuelveCaso() {
	auto arbol = leerArbol();
	if (estaEquilibrado(arbol) != -1)
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

