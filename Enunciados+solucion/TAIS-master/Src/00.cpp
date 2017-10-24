#include <iostream>
#include <algorithm>
#include "BinTree.h"
using namespace std;

// Calcular la altura maxima del arbol
int alturaArbol(BinTree<char> arbol) {
	if (arbol.empty())
		return 0;
	return std::max(alturaArbol(arbol.left()), alturaArbol(arbol.right())) + 1;
}

// Construir un arbol y develverlo
BinTree<char> leerArbol(){
	char c;
	cin >> c;
	if (c == '.')
		return BinTree<char>();
	BinTree<char> lArbol = leerArbol();
	BinTree<char> rArbol = leerArbol();
	return BinTree<char>(lArbol, c, rArbol);
}

void resuelveCaso(){
	BinTree<char> arbol;

	//leer datos de entrada
	arbol = leerArbol();

	// Devolver la altura pasando el arbol como parametro
	int sol = alturaArbol(arbol);

	// Imprimir el solucion
	cout << sol << endl;
}

int main(){
	int numCaso;
	cin >> numCaso;
	for (int i = 0; i < numCaso; i++)
	{
		resuelveCaso();
	}
	return 0;
}