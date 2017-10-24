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
BinTree<char> leerArbol() {
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

// dado un �rbol binario, comprueba la altura de cada uno de los sub�rboles y nos indica si esta equilibrado 
// lineal en el n�mero N de nodos del �rbol, O(N)
bool esEquilibrado(BinTree<char> const& arbol, int & a){
	bool aux = true;
	int aLeft = 0, aRight=0;
	if (!arbol.empty()){
		if (arbol.left().empty() && arbol.right().empty()) {
			a++;
			return true;
		}
		else{
			if (!arbol.left().empty())
				aux = esEquilibrado(arbol.left(), aLeft);
			if (!arbol.right().empty() && aux)
				aux = esEquilibrado(arbol.right(), aRight);
			if (abs(aLeft - aRight) > 1 || !aux)
				return false;
			else
				a = max(aLeft, aRight) + 1;
			return true;
		}
	}
	else
		return true;
}

//Caso 1
// resuelve un caso de prueba
void resuelveCaso() {
	int a = 0;
	auto arbol = leerArbol();
	bool sol = esEquilibrado(arbol, a);
	if (sol)
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
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