//TAIS04 Fernando Miñambres y Juan José Prieto
//
// El problema se resuelve utilizando el algoritmo de Floyd para calcular recursivamente
// el camino minimo desde i hasta j pasando por los vertices desde 1 hasta k, siendo:
// Para todo i,j,k <= n:
// Matriz[i][j] = 0     Si i == j.
// Matriz[i][j] = Matriz[i][k] + Matriz[k][j];   Si Matriz[i][k] + Matriz[k][j] < Matriz[i][j]   Si hay arista de i a j.
// Matriz[i][j] = infinito   En otro caso.
//
// Finalmente se recorre la solucion para buscar el camino mas largo, que sera el 
// mayor grado de separación.
//
// El coste de la función es O(n^3) en tiempo y O(1) en espacio
// adicional, siendo n el número de personas en la red.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits> 
#include <climits>
#include <string>
#include <array>
#include "Matriz.h"

using namespace std;

const int INF = 1000000000;

int calculaRelaciones(Matriz<int> const& G) {
	Matriz<int> C = G;

	size_t n = G.numfils() - 1;

	// actualizaciones de la matriz
	for (size_t k = 1; k <= n; ++k) {
		for (size_t i = 1; i <= n; ++i) {
			for (size_t j = 1; j <= n; ++j) {
				int temp = C[i][k] + C[k][j];
				if (temp < C[i][j]) { // es mejor pasar por k
					C[i][j] = temp;
				}
			}
		}
	}

	int maximoCamino = 0;
	bool conectado = true;
	for (size_t i = 1; i <= n; ++i) {
		for (size_t j = 1; j <= n; ++j) {
			if (i != j && C[i][j] < INF) {
				if (C[i][j] > maximoCamino) {
					maximoCamino = C[i][j];
				}
			}
			if (j > i && C[i][j] >= INF) conectado = false;
		}
	}

	if (conectado)	return maximoCamino;
	else return -1;

}

bool resuelveCaso() {
	int P, R;
	cin >> P >> R;
	if (!cin)
		return false;

	Matriz<int> grafo(P + 1, P + 1, INF);
	for (size_t i = 1; i <= P; ++i)
		grafo[i][i] = 0;

	vector<string> nombres(P);
	size_t u, v;
	for (size_t i = 1; i <= R; ++i) { // leer aristas
		string n1, n2;
		cin >> n1 >> n2;

		// Lectura de las relaciones, guardando en un vector
		// los nombres para asociarlos a un entero.
		bool n1Enc = false, n2Enc = false; int j = 0;
		while (!n1Enc || !n2Enc) {
			if (n1 == nombres[j]) {
				n1Enc = true;
				u = j + 1;
			}
			else if (n2 == nombres[j]) {
				n2Enc = true;
				v = j + 1;
			}
			else if (nombres[j] == "") {
				if (!n1Enc) {
					nombres[j] = n1;
					n1Enc = true;
					u = j + 1;
				}
				else if (!n2Enc) {
					nombres[j] = n2;
					n2Enc = true;
					v = j + 1;
				}
			}
			j++;
		}
		grafo[u][v] = 1;
		grafo[v][u] = 1;
	}

	int r = calculaRelaciones(grafo);
	if (r != -1) {
		cout << r << endl;
	}
	else {
		cout << "DESCONECTADA" << endl;
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