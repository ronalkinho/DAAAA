#include <iostream>
#include <climits>
#include <fstream>
#include <algorithm>
#include "BinTree.h"
using namespace std;

int alturaArbol(BinTree<int> arbol);

// Comprobar si arbol esta ordenado
// O(n), siendo n el numero de nodos del arbol
bool AVL(BinTree<int> const& arbol, int &minimo, int &maximo) {
	
	if (arbol.empty())
		return true;
	else {

		int minAux = arbol.root();
		int maxAux = arbol.root();
		bool ordenado = ((minimo < arbol.root()) && (arbol.root() < maximo));
		bool hIz = AVL(arbol.left(), minimo, maxAux);
		bool hDr = AVL(arbol.right(), minAux, maximo);

		if (arbol.root() < minimo)
			minimo = arbol.root();
		if (arbol.root() > maximo)
			maximo = arbol.root();

		return hIz && hDr & ordenado;

	}
}


// devolver la diferencia de altura de dos arboles
int diferenciaAltura(int a1, int a2) {
	return a1 >= a2 ? a1 - a2 : a2 - a1;
}

// Calcular la altura maxima del arbol
int alturaArbol(BinTree<int> arbol) {
	if (arbol.empty())
		return 0;
	return std::max(alturaArbol(arbol.left()), alturaArbol(arbol.right())) + 1;
}

// Averiaguar si arbol esta equilibrado
bool equilibrado(BinTree<int> arbol) {
	if (arbol.empty())
		return true;
	return equilibrado(arbol.left()) &&
		equilibrado(arbol.right()) &&
		diferenciaAltura(alturaArbol(arbol.left()), alturaArbol(arbol.right())) <= 1;
}

// Averiguar si arbol es de AVL
bool arbolAVL(BinTree<int> arbol) {
	int minimo = 0, maximo = INT_MAX;
	return equilibrado(arbol) && AVL(arbol, minimo, maximo);
}

// Construir un arbol y develverlo
BinTree<int> leerArbol() {
	int n;
	cin >> n;
	if (n == -1)
		return BinTree<int>();
	BinTree<int> lArbol = leerArbol();
	BinTree<int> rArbol = leerArbol();
	return BinTree<int>(lArbol, n, rArbol);
}

void resuelveCaso() {
	BinTree<int> arbol;

	//leer datos de entrada
	arbol = leerArbol();

	// Devolver la altura pasando el arbol como parametro
	bool sol = arbolAVL(arbol);

	// Imprimir el solucion
	if (sol)
		cout << "SI";
	else
		cout << "NO";
	cout << endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCaso;
	cin >> numCaso;
	for (int i = 0; i < numCaso; i++)
	{
		resuelveCaso();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}