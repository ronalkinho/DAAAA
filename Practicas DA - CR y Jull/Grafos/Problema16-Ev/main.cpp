// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

/*
Resolvemos el problema empleando un array de booleanos,una cola de m�nimos, una cola normal y un grafo UF. 
El array de booleanos se emplea para saber si hemos pasado por todas las islas, puesto que cada posici�n es una isla.
La cola contiene las aristas ordenadas seg�n su valor, es decir, el coste del puente.
La cola normal va a ser el n�mero de puentes que vamos a construir con el menor coste posible.
El grafo va a ser la red m�nima que se crea con todos los puentes que se dan.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"

using namespace std;
/*
Al principio formamos la cola que contiene todos los puentes ordenados de menor a mayor por su coste y tambi�n ponemos todas
las islas a false como que a�n no las hemos alcanzado.
Tras esto lo que haremos ser� ir sacando arista a arista (seg�n su coste) e ir formando el grafo con uniones si no existe ya 
una conexi�n entre ambos v�rtices de la arista, si esta conexi�n a�n no se ha hecho, la realizamos, marcamos ambas islas como
que las hemos alcanzado y dicho puento lo metemos a la cola de puentes para construir.
Una vez sepamos todos los puentes que vayamos a construir hay que comprobar que alcanzamos todas las islas y que todas ellas 
est�n en el mismo conjunto del grafo, si esto se cumple devolvemos el coste total de los puentes.
En el caso de que solo haya una isla el coste siempre es 0. 

Coste: es del O(V + ElogE) siendo V el n�mero de islas y E el n�mero de puentes.
*/
int costePuentes(int islas, int puentes){
	if (islas == 1)
		return 0;

	int coste = 0, isla1, isla2, dist;
	PriorityQueue<Arista<int>> aristasOrd(puentes);
	queue<Arista<int>> totalPuentes;
	ConjuntosDisjuntos grafoPuentes(islas+1);
	bool *totalIslas;
	totalIslas = (bool*)malloc((islas+1)*sizeof(bool));
	bool ok = true;

	//Bucle con el cual se forma la cola ordenada de menos a mayor valor de arista
	for (int i = 0; i < puentes; i++){
		cin >> isla1 >> isla2 >> dist;
		Arista<int> a(isla1, isla2, dist);
		aristasOrd.push(a);
	}
	//Bucle para inicializar el vector de booleanos con las islas que hemos alcanzado
	for (int i = 0; i <= islas; i++){
		totalIslas[i] = false;
	}

	//Algoritmo Kruskal para la formaci�n de un grafo con todos los puentes y sus conexiones	
	while (!aristasOrd.empty() && totalPuentes.size() < islas - 1){
		Arista<int> e = aristasOrd.top();
		aristasOrd.pop();
		int v = e.uno(), w = e.otro(v), i = grafoPuentes.buscar(v), j = grafoPuentes.buscar(w);
		if (i != j){
			grafoPuentes.unir(v, w);
			totalIslas[v] = true;
			totalIslas[w] = true;
			totalPuentes.push(e);
		}
	}

	//Bucle para recorrer la cola de puentes creada y adem�s ver si hemos pasado por todas las islas
	int w = 1;
	while (ok && w <= islas){
		if (!totalPuentes.empty()){
			coste += totalPuentes.front().valor();
			totalPuentes.pop();
		}
		if (!totalIslas[w])
			ok = false;
		w++;
	}

	free(totalIslas);

	if (ok && grafoPuentes.count() == 2)
		return coste;
	else
		return -1;
}

bool resuelveCaso() {
	int islas, puentes, coste;
	
	cin >> islas >> puentes;

	if (!cin)
		return false;
	
	coste = costePuentes(islas, puentes);
	
	if (coste >= 0)
		cout << coste << endl;
	else
		cout << "No hay puentes suficientes" << endl;

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
