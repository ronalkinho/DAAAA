// TAIS03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include "Grafo.h"
#include "Amigos.h"
#include <vector>
using namespace std;

//Lineal en el número de aristas del grafo
void poneArista(Grafo &g, int a) {

	int v1, v2;

	for (int i = 0; i < a; i++) {

		cin >> v1;
		cin >> v2;

		v1 = v1 - 1;
		v2 = v2 - 1;

		g.ponArista(v1, v2);

	}

}

//Lineal en el número de vertices del grafo
int misAmigos(Grafo g) {

	int amigos = 0;
	Amigos a(g);
	amigos = a.maxAmigos();

	return amigos;
}

bool resuelveCaso() {

	int v = 0;
	int a;

	cin >> v;

	Grafo g(v);

	cin >> a;

	poneArista(g, a);

	Amigos amigos(g);



	cout << amigos.maxAmigos() << endl;


	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;

	cin >> casos;

	for (int i = 0; i < casos; i++)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}