// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

struct conferencia
{
	int inicio;
	int fin;
};

class comparator{
public:
	bool operator()(const conferencia c1, const conferencia c2){
		if (c1.inicio < c2.inicio){
			return true;
		}
		else {
			return false;
		}
	}
};

bool resuelveCaso(){

	int n;
	cin >> n;

	if (n == 0) return false;


	PriorityQueue<conferencia, comparator> colaConferencia;

	conferencia aux;
	for (int i = 0; i < n; i++)
	{
		cin >> aux.inicio >> aux.fin;
		colaConferencia.push(aux);
	}

	int nSalas = 1;
	PriorityQueue<int> colaSalas;
	colaSalas.push(colaConferencia.top().fin);
	colaConferencia.pop();

	for (int i = 1; i < n; i++)
	{
		aux = colaConferencia.top(); colaConferencia.pop();
		if (aux.inicio >= colaSalas.top()){
			colaSalas.pop();
			colaSalas.push(aux.fin);
		}
		else {
			colaSalas.push(aux.fin);
			nSalas++;
		}
	}

	cout << nSalas << endl;

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