/*
* Milagros del Rocío Peña Quineche
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

#include "PriorityQueue.h"

class Musicos {
public:

	Musicos() {};
	Musicos(int m, int p) : musicos(m), partituras(p), prioridad(m/p) {};

	friend bool operator>(Musicos a, Musicos b) {
		bool mas = false;

		if (a.prioridad > b.prioridad)
			mas = true;

		return mas;
	}
	
	void setPrioridad(int p) {
		prioridad = p;
	}

	int getPrioridad() {
		return prioridad;
	}

	int getMusicos() {
		return musicos;
	}

	int getPartituras() {
		return partituras;
	}

	void setPartituras(int p) {
		partituras = p;
	}

private:
	int musicos;
	int partituras;
	int prioridad;
};

//Coste lineal en el nº partituras menos el nº de músicos
int resuelveCaso(PriorityQueue<Musicos, std::greater<Musicos>> &cola, int p) {
	int masConcurrido = 0;
	p -= cola.size();
	
	while (p > 0) {
		Musicos m = cola.top();
		cola.pop();
		int partituras = m.getPartituras();
		int musicos = m.getMusicos();
		
		partituras++;

		int prio = musicos / partituras;

		if (musicos % partituras != 0)
			prio++;

		m.setPartituras(partituras);
		m.setPrioridad(prio);

		p--;
		cola.push(m);
	}

	Musicos m = cola.top();

	masConcurrido = m.getPrioridad();

	return masConcurrido;
}



int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int partituras;
	std::cin >> partituras;

	while (!cin.fail())
	{

		int instrumentos;
		cin >> instrumentos;
		int n;
		PriorityQueue<Musicos, std::greater<Musicos>> cola = PriorityQueue<Musicos, std::greater<Musicos>>();

		for (long long int i = 0; i < instrumentos; i++) {
			cin >> n;
			Musicos m(n, 1);
			cola.push(m);
		}

		cout << resuelveCaso(cola, partituras) << endl;

		std::cin >> partituras;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
