// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

struct edificio
{
	int W;
	int E;
};

class comparator{
public:
	bool operator()(const edificio e1, const edificio e2){
		if (e1.W < e2.W){
			return true;
		}
		else {
			return false;
		}
	}
};

// O(NlogN), siendo N el numero de edificios(entre 1 y 100000)
bool resuelveCaso(){

	int n;
	cin >> n;

	if (n == 0) return false;


	PriorityQueue<edificio, comparator> colaEdificio;

	edificio aux;
	for (int i = 0; i < n; i++)
	{
		cin >> aux.W >> aux.E;
		colaEdificio.push(aux);
	}

	int nPasadizos = 1;
	aux = colaEdificio.top(); colaEdificio.pop();
	for (int i = 1; i < n; i++)
	{
		edificio siguiente = colaEdificio.top(); colaEdificio.pop();
		if (siguiente.W >= aux.E){
			nPasadizos++;
			aux = siguiente;
		}
		else {
			if (siguiente.E < aux.E){
				aux = siguiente;
			}
		}
	}

	cout << nPasadizos << endl;

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
	system("pause");
#endif

	return 0;
}