// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

/*
Resolvemos el problema mediante el uso de un algoritmo voraz el cual va a usar 2 colas de prioridad,
una de m�nimos en la cual guardar� los resultados de los rivales y una de m�ximos en la que guardar�
los resultados de los broncos.
Despu�s simplemente ir� sacando resultados mientras que el resultado de los broncos sea mayor que el
de sus rivales y no se haya acabado la temporada. Esos resultados que sacamos los restamos y vamos 
acumulando las diferencias.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

/*
Coste: es de O(N log N) siendo N el n�mero de los partidos de la temporada
*/
void resuelveCaso(int partidos) {
	int diferencia=0, res;

	PriorityQueue<int, std::greater<int>> broncos(partidos);
	PriorityQueue<int> rivales(partidos);
	
	for (int i = 0; i < partidos; ++i){
		cin >> res;
		rivales.push(res);
	}

	for (int i = 0; i < partidos; ++i){
		cin >> res;
		broncos.push(res);
	}

	while (!broncos.empty() && broncos.top() > rivales.top()) {
		diferencia += (broncos.top() - rivales.top());
		broncos.pop();
		rivales.pop();
	}

	cout << diferencia << endl;
}

int main() {
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int partidos;
	cin >> partidos;
	while (partidos != 0){
		resuelveCaso(partidos);
		cin >> partidos;
	}
	
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}
