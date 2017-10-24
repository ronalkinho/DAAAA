// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

/*
Resolvemos el problema mediante el uso del algoritmo de dijkstra.
Para ello creamos un array de tiempos que en cada posici�n va a guardar la el tiempo
desde el v�rtice origen, el 0, hasta el v�rtice posici�n, es decir, timeTo[3]=34 indica que 
el tiempo entre la p�gina 0 y la 3 es 34.
Utilizamos otro array de tiempos de carga de cada p�gina para as� consultarlo cada vez 
que pasemos por una.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

using namespace std;

const int INF = 1e9;

/*
En el caso de que el tiempo que obtenemos hasta un v�rtice w sea mejor por esta arista que por un 
camino anterior se actualiza.

Coste: es del O(log V) siendo V el n�mero de v�rtices de la cola de prioridad indexada
*/
void relax(AristaDirigida<int> e, IndexPQ<int> & pq, int carga[], int *timeTo)
{
	int v = e.from(), w = e.to();
	if (timeTo[w] > timeTo[v] + carga[w] + e.valor()){
		timeTo[w] = timeTo[v] + carga[w] + e.valor();
		pq.update(w, timeTo[w]);
	}
}

/*
En un primer momento leo los tiempos de carga de cada p�gina y establezco los tiempos a todos los 
v�rtices que ser� INF (un n�mero muy grande como para considerearse infinito) menos el de la p�gina
de inicio cuyo tiempo es el suyo propio de carga.
Despu�s leemos todas las aristas y formamos el grafo dirigido y valorado.
Un vez tengamos todos los datos recogidos recorremos v�rtice a v�rtice empezando por el origen (despu�s
por sus adyacentes y as� sucesivamente) y vamos estableciendo los tiempos hasta todas las p�ginas que 
alcancemos y en el caso de que un tiempo obtenido por una arista sea m�s eficiente que uno anterior se
actualiza.

Coste: es del O(V + V + E + E log V) siendo V el n�mero de v�rtices del grafo y E el n�mero de aristas
que forman el grafo dirigido
*/
void resuelveCaso(int n){
	int *timeTo, *carga;
	GrafoDirigidoValorado<int> g(n);
	int v, enlaces, c, uno, otro, valor;
	IndexPQ<int> pq(n);
	timeTo = new int[n];
	carga = new int[n];
	
	//Guardamos los tiempos de carga de cada p�gina e inicializamos la distancia de la 
	//p�gina 0 a su tiempo de carga
	for (int i = 0; i < n; ++i){
		cin >> c;
		carga[i] = c;
	}

	//Ponemos las distancias a todos los v�rtices a la distancia m�xima y la del 0 a la 
	//m�nima por ser el mismo
	timeTo[0] = carga[0];
	for (int i = 1; i < n; i++)
		timeTo[i] = INF;

	//Creamos el grafo de todos los enlaces entre las p�ginas
	cin >> enlaces;
	for (int i = 0; i < enlaces; ++i){
		cin >> uno >> otro >> valor;
		AristaDirigida<int> e(uno-1, otro-1, valor);
		g.ponArista(e);
	}
	
	pq.push(0, timeTo[0]);
	while (!pq.empty()){
		v = pq.top().elem;
		pq.pop();
		for (AristaDirigida<int> e : g.adj(v))
			relax(e, pq, carga, timeTo);
	}

	if (timeTo[n - 1] == INF)
		cout << "IMPOSIBLE" << endl;
	else
		cout << timeTo[n - 1] << endl;

	delete[] carga;
	delete[] timeTo;
}


int main() {
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int num;
	std::cin >> num;
	while (num != 0){
		resuelveCaso(num);
		std::cin >> num;
	}
	
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}
