/*
* Milagros del Rocío Peña Quineche
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;

#include "PriorityQueue.h"

//Coste lineal en los elementos de la cola de prioridad
long long int resuelveCaso(PriorityQueue<long long int> &cola) {
	long long int gorras = 0;
	long long int sum = 0;

	while (cola.size() != 1) {
		sum += cola.top();
		cola.pop();
		sum += cola.top();
		cola.pop();
		cola.push(sum);
		gorras += sum;
		sum = 0;
	}

	return gorras;
}



int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	long long int equipos;
	std::cin >> equipos;

	while (equipos != 0)
	{
	
		long long int n;
		PriorityQueue<long long int> cola = PriorityQueue<long long int>();

		for (long long int i = 0; i < equipos; i++) {
			cin >> n;
			cola.push(n);
		}

		cout << resuelveCaso(cola) << endl;
			
		std::cin >> equipos;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
