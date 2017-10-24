//TAIS04 Fernando Miñambres y Juan José Prieto
//
// El problema se resuelve utilizando una matriz para calcular recursivamente el
// maximo valor que podemos llevar hasta i con el tiempo j, Siendo:
//
// Matriz[i][j] = mochila[i][j] = mochila[i - 1][j];   Si la profundidad * 3 > j;
// Matriz[i][j] = max(mochila[i - 1][j], mochila[i - 1][j - (tesoros[i].prof * 3)] + tesoros[i].cant);   En otro caso
// Inicializamos la Matriz con todos los valores a 0.
//
// Despues recorremos la solucion para buscar cuales y cuantos cogemos, en funcion de si Matriz[i][r] es igual a
// Matriz[i-1][r], siendo r la cantidad total de segundos que se puede sumergir menos los gaste en coger la solucion.
//
// El coste de la función es de O(nT) tanto en tiempo como en espacio, siendo n el numero de tesoros y T el tiempo que 
// puede estar sumergido.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "Matriz.h"

using namespace std;

struct Tesoro {
	int prof;
	int cant;
};

void recogeTesoros(vector<Tesoro> const& tesoros, int T, int & maximoRecogible, int & cuantos, vector<bool> & cuales) {
	size_t n = tesoros.size() - 1;
	Matriz<int> mochila(n + 1, T + 1, 0);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= T; ++j) {
			if (tesoros[i].prof * 3 > j)
				mochila[i][j] = mochila[i - 1][j];
			else
				mochila[i][j] = max(mochila[i - 1][j], mochila[i - 1][j - (tesoros[i].prof * 3)] + tesoros[i].cant);
		}
	}
	maximoRecogible = mochila[n][T];

	int resto = T;
	for (size_t i = n; i >= 1; --i) {
		if (mochila[i][resto] == mochila[i - 1][resto]) {
			cuales[i] = false;
		}
		else {
			cuales[i] = true;
			resto = resto - (tesoros[i].prof * 3);
			cuantos++;
		}
	}
}

bool resuelveCaso() {
	int T, N;
	cin >> T >> N;
	if (!cin)
		return false;

	vector<Tesoro> tesoros(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> tesoros[i].prof >> tesoros[i].cant;
	}

	int maximoRecogible = 0, cuantos = 0;
	vector<bool> cuales(N + 1);
	recogeTesoros(tesoros, T, maximoRecogible, cuantos, cuales);

	cout << maximoRecogible << endl;
	cout << cuantos << endl;
	for (int i = 1; i <= N; i++) {
		if (cuales[i])
			cout << tesoros[i].prof << " " << tesoros[i].cant << endl;
	}
	cout << "----" << endl;

	return true;
}



int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {

	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}