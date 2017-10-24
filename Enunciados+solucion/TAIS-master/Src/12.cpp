// TAIS03 LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include "maquinaCalculadora.h"
using namespace std;

bool resuelveCaso(){
	int n, m;
	cin >> n >> m;
	if (!cin)
		return false;

	GrafoCal grafo(n, m);

	int sol = grafo.menorPulsacion();

	cout << sol << endl;

	return true;
}

int main(){
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