// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema mediante el uso de un algoritmo voraz el cual va a usar 1 cola de prioridad 
que guarda estructuras de los edificios, con una coordenada de inicio y otra de fin, esta cola es de 
mínimos, ordenandola por la coordenada donde acaba el edificio.
Después vamos sacando edificios y creando tuneles al final de estos, para ello tenemos que comprobar que 
el inicio del edificio este despues del tunel ultimo construido, lo que significaria que no tiene ningun 
tunel que le atraviese.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

struct t_edificio{
	int ini;
	int fin;
};

bool operator <(t_edificio a, t_edificio b){
	return a.fin < b.fin;
}


/*
Coste: es de O(N log N) siendo N el número de edificios
*/
void resuelveCaso(int edificios) {
	int tuneles=0, ini , fin, ult_tunel = -1;
	t_edificio edif;
	PriorityQueue<t_edificio> apart(edificios);
	
	for (int i = 0; i < edificios; ++i){
		cin >> ini >> fin;
		edif.ini = ini;
		edif.fin = fin;
		apart.push(edif);
	}

	while (!apart.empty()) {
		if (apart.top().ini >= ult_tunel){
			ult_tunel = apart.top().fin;
			++tuneles;
		}
		apart.pop();
	}

	cout << tuneles << endl;
}

int main() {
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int edificios;
	cin >> edificios;
	while (edificios != 0){
		resuelveCaso(edificios);
		cin >> edificios;
	}
	
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}
