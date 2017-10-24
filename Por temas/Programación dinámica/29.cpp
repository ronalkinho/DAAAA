// TAIS04 Fernando Miñambres y Juan José Prieto
//
// El problema se resuelve utilizando un vector para calcular recursivamente el minimo numero
// de dardos necesarios para alcanzar la cantidad j desde el sector i. Siendo:
//
// Vector[j] = min(Vector[j], Vector[j - Sector[i]] + 1);
// Inicializamos con Vector[0] = 0;
//
// La solucion estará en Vector[puntuacion a alcanzar]. Recorremos este vector
// buscando los sectores forman parte de la solución.
//
// El coste de la función es de O(nP) en tiempo y O(P) en espacio,
// siendo n el numero de sectores de la diana y P la puntuación
// a alcanzar.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits> 
#include <climits>
#include "Matriz.h"

using namespace std;

vector<int> calculaMinimoDardos(vector<int> const& diana, int P, int & numTiradas) {
	size_t n = diana.size() - 1;
	vector<signed int> tiradas(P + 1, INT_MAX - 1);
	tiradas[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = diana[i]; j <= P; j++) {
			tiradas[j] = min(tiradas[j], tiradas[j - diana[i]] + 1);
		}
	}

	numTiradas = tiradas[P];

	if (numTiradas != INT_MAX - 1) {
		size_t n = diana.size() - 1;
		vector<int> cuantas(n + 1, 0);
		int i = n; int j = P;
		while (j > 0) {
			if (diana[i] <= j && tiradas[j] == tiradas[j - diana[i]] + 1) {
				++cuantas[i];
				j = j - diana[i];
			}
			else
				--i;
		}
		return cuantas;
	}
	else {
		numTiradas = -1;
		return{};
	}
}

bool resuelveCaso() {
	int P, N;
	cin >> P >> N;
	if (!cin)
		return false;

	vector<int> diana(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> diana[i];
	}

	sort(diana.begin(), diana.end(), less<int>());

	int numTiradas = 0;
	vector<int> cuantas = calculaMinimoDardos(diana, P, numTiradas);

	if (numTiradas != -1) {
		cout << numTiradas << ":";
		for (int i = N; i > 0; i--) {
			for (int j = cuantas[i]; j > 0; j--) {
				cout << " " << diana[i];
			}
		}
		cout << endl;
	}
	else {
		cout << "Imposible" << endl;
	}


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