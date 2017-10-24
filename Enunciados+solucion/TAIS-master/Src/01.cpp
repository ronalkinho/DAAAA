#include <iostream>
#include <algorithm>
#include "BinTree.h"
using namespace std;

// devolver la diferencia de altura de dos arboles
int diferenciaAltura(int a1, int a2){
	return a1 >= a2 ? a1 - a2 : a2 - a1;
}

// Calcular la altura maxima del arbol
int alturaArbol(BinTree<char> arbol) {
	if (arbol.empty())
		return 0;
	return std::max(alturaArbol(arbol.left()),alturaArbol(arbol.right())) + 1;
}

// Averiaguar si arbol esta equilibrado
bool equilibrado(BinTree<char> arbol){
	if (arbol.empty())
		return true;
	return equilibrado(arbol.left()) &&
		   equilibrado(arbol.right()) &&
		   diferenciaAltura(alturaArbol(arbol.left()), alturaArbol(arbol.right())) <= 1;
}

// Construir un arbol y develverlo
BinTree<char> leerArbol() {
	char raiz;
	std::cin >> raiz;
	if (raiz == '.') { // es un ¨¢rbol vac¨ªo
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}

void resuelveCaso(){
	BinTree<char> arbol;

	//leer datos de entrada
	arbol = leerArbol();

	// Devolver la altura pasando el arbol como parametro
	bool sol = equilibrado(arbol);

	// Imprimir el solucion
	if (sol)
		cout << "SI";
	else
		cout << "NO";
	cout << endl;
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