// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

/*
Resolvemos el problema empleando el algoritmo de la b�squeda en anchura con la salvedad de que no hay 
un grafo como tal, sino que est� impl�cito. Entonces al no haber grafo no hay v�rtices adyacentes ya
establecidos sino que tenemos nosotros que calcularlos mediante las f�rmulas de la calculadora, por 
tanto cada v�rtice va a tener 3 adyacentes tras �l, que son �l mismo sumado 1, multiplicado por 2 o
dividido entre 3 (todos ellos m�dulo 10000), y seg�n llegamos a lo v�rtices nuevos vamos estableciento
en un vector la distancia desde el origen al v�rtice actual.
El algoritmo acaba no con con el recorrido de todos los caminos a todos los v�rtices para encontrar los 
caminos m�nimos, sino cuando encontramos el v�rtice destino, en ese caso solo tenemos que devolver la 
distancia hasta �l.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"

using namespace std;

const int MAX = 10000;

/*
Coste: el coste de este algoritmo es del O(N logN) siendo N la relaci�n de distancia m�nima que existe entre 
el v�rtice de origen y el de destino en la b�squeda por anchura
*/
int costePulsaciones(int orig, int dest){
	int w, v = orig;
	bool marked[MAX];
	int distTo[MAX];
	queue<int> q;

	for (int i = 0; i < MAX; i++){
		marked[i] = false;
	}

	marked[orig] = true;
	q.push(orig); 
	distTo[orig] = 0;

	while (v != dest){
		w = (v + 1) % MAX;
		if (!marked[w]){
			marked[w] = true;
			q.push(w);
			distTo[w] = distTo[v] + 1;
		}

		w = (v * 2) % MAX;
		if (!marked[w]){
			marked[w] = true;
			q.push(w);
			distTo[w] = distTo[v] + 1;
		}

		w = (v / 3) % MAX;
		if (!marked[w]){
			marked[w] = true;
			q.push(w);
			distTo[w] = distTo[v] + 1;
		}

		v = q.front(); 
		q.pop();
	}

	return distTo[v];
}

bool resuelveCaso() {
	int orig, dest;
	
	cin >> orig >> dest;

	if (!cin)
		return false;
	
	cout << costePulsaciones(orig, dest) << endl;

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
