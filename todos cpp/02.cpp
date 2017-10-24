// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

#include "BinTree.h"

BinTree<int> leerArbol() {
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

// Coste lineal en el nº de nodos del arbol.
int equilibrado(BinTree<int> const& arbol){
	if (arbol.empty()) return 0;
	else {
		int alturaIzq = equilibrado(arbol.left());
		int alturaDer = equilibrado(arbol.right());
		if (alturaIzq == -1 || alturaDer == -1 || abs(alturaIzq - alturaDer) > 1) return -1;
		else return max(alturaIzq, alturaDer) + 1;
	}
}

// Coste lineal en el nº de nodos del arbol.
int ordenado(BinTree<int> const& arbol, bool derecho){
	if (arbol.empty()) return -1;
	else {
		int maxIzq = ordenado(arbol.left(), false);
		int minDer = ordenado(arbol.right(), true);
		if (maxIzq != -1 && (maxIzq == -2 || maxIzq >= arbol.root())) return -2;
		if (minDer != -1 && (minDer == -2 || minDer <= arbol.root())) return -2;
		if (derecho)
		{
			if (maxIzq != -1) return maxIzq;
			else return arbol.root();
		}
		else
		{
			if (minDer != -1) return minDer;
			else return arbol.root();
		}
	}
}

// resuelve un caso de prueba
void resuelveCaso() {
	auto arbol = leerArbol();
	int sol1 = equilibrado(arbol);
	int sol2 = ordenado(arbol, true); // Poner true o false en la primera llamada es irrelevante.
	if (sol1 != -1 && sol2 != -2) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
