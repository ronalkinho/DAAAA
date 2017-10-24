// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>
#include "BinTree.h"
//#include "TreeMap_AVL.h"
//#include "TreeMap_RB.h"

using namespace std;

// lee un �rbol binario de la entrada est�ndar
BinTree<int> leerArbol() {
	char raiz;
	std::cin >> raiz;
	if (raiz == '.') { // es un �rbol vac�o
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}

// dado un �rbol binario, calcula su altura
// lineal en el n�mero N de nodos del �rbol, O(N)
int altura(BinTree<int> const& arbol){
	if (arbol.empty()) {
		return 0;
	}
	else {
		return 1 + std::max(altura(arbol.left()), altura(arbol.right()));
	}
}

//Caso 1
// resuelve un caso de prueba
void resuelveCaso() {
	auto arbol = leerArbol();
	int sol = altura(arbol);
	std::cout << sol << "\n";
}

// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N))
/*int resolver(int datos) {

}*/

int main() {
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

//Caso 2
/*
bool resuelveCaso() {
	h leer los datos de la entrada i
		if (caso especial)
			return false;
	Solucion sol = resolver(datos);
	h escribir sol i
		return true;
}
int main() {
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	while (resuelveCaso());

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}*/

//Caso 3
/*
bool resuelveCaso() {
	h leer los datos de la entrada i
		if (!cin) // fin de la entrada
			return false;
	Solucion sol = resolver(datos);
	h escribir sol i
		return true;
}
int main() {
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	while (resuelveCaso());

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}	
*/