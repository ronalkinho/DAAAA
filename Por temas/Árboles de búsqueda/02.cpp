// TAIS04 - Fernando Miñambres y Juan José Prieto
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

#include "BinTree.h"

// lee un árbol binario de la entrada estándar
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

// Función que recorre un arbol en preorden para comprobar si es AVL o no.
//
// Para ver la diferencia de alturas entre los hijos se utiliza la variable "altura", que se irá
// actualizando en cada nodo. A la salida de la llamada a los hijos se comprueba que la diferencia
// es menor o igual que uno.
//
// Para ver si esta ordenado se utilizan la variables "maximo" y "minimo" y se comprueba que la 
// raiz no sobrepasa ninguno de los dos. Para ello se pasan como parametro en la llamada a los 
// hijos. Si es el izquierdo, el minimo se mantiene y el maximo es igual a la raiz actual; si es 
// el derecho, mantiene el maximo y el minimo es la raiz actual.
//
//El coste de esta función es O(n), siendo n el número de nodos del árbol.
void compruebaAVL(BinTree<int> const& arbol, bool &esAVL, int &altura, int minimo, int maximo) {
	if (arbol.empty()) {

	}
	else {
		// Actualizamos la altura
		altura++;
		int alturaActual = altura;

		// Comprobamos los limites para ver si está ordenado.
		if (arbol.root() <= minimo) {
			esAVL = false;
		}
		if (arbol.root() >= maximo) {
			esAVL = false;
		}

		// Llamamos a los hijos y guardamos sus alturas.
		compruebaAVL(arbol.left(), esAVL, altura, minimo, arbol.root());
		int alturaHijoIzquierdo = altura;
		altura = alturaActual;

		compruebaAVL(arbol.right(), esAVL, altura, arbol.root(), maximo);
		int alturaHijoDerecho = altura;

		// Comprobamos la diferencia de alutras.
		if (abs(alturaHijoIzquierdo - alturaHijoDerecho) > 1) {
			esAVL = false;
		}

		// Actualizamos la altura en funcion de los hijos.
		altura = max(alturaHijoIzquierdo, alturaHijoDerecho);
	}
}


// resuelve un caso de prueba
void resuelveCaso() {
	auto arbol = leerArbol();
	bool AVL = true;
	int altura = 0, minimo = -1, maximo = numeric_limits<int>::max();
	compruebaAVL(arbol, AVL, altura, minimo, maximo);
	if (AVL) std::cout << "SI" << endl;
	else std::cout << "NO" << endl;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}