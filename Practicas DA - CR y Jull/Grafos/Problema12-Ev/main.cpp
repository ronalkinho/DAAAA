// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema empleando el algoritmo de la búsqueda en anchura con la salvedad de que no hay 
un grafo como tal, sino que está implícito. Entonces al no haber grafo no hay vértices adyacentes ya
establecidos sino que tenemos nosotros que calcularlos mediante las fórmulas de la calculadora, por 
tanto cada vértice va a tener 3 adyacentes tras él, que son él mismo sumado 1, multiplicado por 2 o
dividido entre 3 (todos ellos módulo 10000), y según llegamos a lo vértices nuevos vamos estableciento
en un vector la distancia desde el origen al vértice actual.
El algoritmo acaba no con con el recorrido de todos los caminos a todos los vértices para encontrar los 
caminos mínimos, sino cuando encontramos el vértice destino, en ese caso solo tenemos que devolver la 
distancia hasta él.
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
Coste: el coste de este algoritmo es del O(N logN) siendo N la relación de distancia mínima que existe entre 
el vértice de origen y el de destino en la búsqueda por anchura
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
