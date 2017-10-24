// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

/*
Para solucionar el problema comprobamos la altura de cada subarbol y de esta manera averiguamos si esta
equilibrado, si lo esta ademas devolvemos para cada nodo el valor maximo y minimo de sus hijos 
(en el caso de que los tenga, de lo contrario su propio valor). 
Con estos valores comprobamos si para cada subarbol se cumple que la raiz es mayor estricto que todos 
los nodos por parte de su hijo izquierdo (de existir) y menor estricto que todos los que provienen de su 
hijo derecho. 
Si se cumplen todas las condiciones o el arbol dado es vaci�n entonces es AVL.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "BinTree.h"
//#include "TreeMap_AVL.h"
//#include "TreeMap_RB.h"

using namespace std;

// lee un �rbol binario de la entrada est�ndar
BinTree<int> leerArbol() {
	int raiz;
	std::cin >> raiz;
	if (raiz == -1) { // es un �rbol vac�o
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol();
		auto dr = leerArbol();
		return{ iz, raiz, dr };
	}
}

/* 
Dado un �rbol binario, comprueba la altura de cada uno de los sub�rboles, nos indica si esta equilibrado y
si los nodos cumplen la relacion de menor mayor respecto a su padre

Coste: lineal en el n�mero N de nodos del �rbol, O(N)
*/ 
bool esAVL(BinTree<int> const& arbol, int & a, int & mn, int & mx){
	bool aux = true;
	int aLeft = 0, aRight = 0, mnI = INT16_MAX, mnD = INT16_MAX, mxI = -1, mxD = -1;
	if (!arbol.empty()){
		if (arbol.left().empty() && arbol.right().empty()) {
			a++;
			mx = arbol.root();
			mn = arbol.root();
			return true;
		}
		else{
			if (!arbol.left().empty())
				aux = esAVL(arbol.left(), aLeft, mnI, mxI) && (arbol.root() > arbol.left().root());

			if (!arbol.right().empty() && aux)
				aux = esAVL(arbol.right(), aRight, mnD, mxD) && (arbol.root() < arbol.right().root());
				
			if ((arbol.root() <= mxI) || (arbol.root() >= mnD) || abs(aLeft - aRight) > 1 || !aux)
				return false;
			else{
				a = max(aLeft, aRight) + 1;
				mn = min(mnI, arbol.root());
				mx = max(mxD, arbol.root());
			}	
			return true;
		}
	}
	else
		return true;
}


//Caso 1
// resuelve un caso de prueba
void resuelveCaso() {
	int a = 0, mn = INT16_MAX, mx = 0;
	auto arbol = leerArbol();
	bool sol = esAVL(arbol, a, mn, mx);
	if (sol)
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
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
		system("PAUSE");
	#endif

	return 0;
}
