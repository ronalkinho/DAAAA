// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

/*
Resolvemos el problema mediante el uso de un algoritmo voraz el cual coge todos los libros que vamos a 
comprar y los inserta en una cola de prioridad de m�ximos.
Despu�s, como las ofertas son de 3x2 calcula cuantas ofertas podemos aplicar seg�n el n�mero de libros a 
comprar por lo que luego solo hay que ir sacando libros de 3 en 3 tantas veces como ofertas nos sea posible
aplicar y quedarnos con el 3� que ser� el que nos regalen, as� obtendremos el mayor descuento posible.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

/*
Coste: es del O(N log N) siendo N el n�mero de libros que se quieren comprar
*/
bool resuelveCaso() {
	int numLibros, ofertas, l, ahorro=0;

	cin >> numLibros;

	if (!cin)
		return false;

	PriorityQueue<int, std::greater<int>> libros(numLibros);
	ofertas = numLibros / 3;
	
	for (int i = 0; i < numLibros; ++i){
		cin >> l;
		libros.push(l);
	}

	for (int i = 0; i < ofertas; ++i) {
		libros.pop();
		libros.pop();
		ahorro += libros.top();
		libros.pop();
	}

	cout << ahorro << endl;

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
