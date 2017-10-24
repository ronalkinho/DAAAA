// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <algorithm>
#include <vector>

using namespace std;


typedef struct  {

	int valor;
	int cantidad;

}Monedas;


class compare {
public:
	bool operator()(Monedas a, Monedas b) {
		return a.valor < b.valor;
	}
};

int MinMonedas(vector<Monedas> &mon, int N, int precio) {

	Matriz<int> minMonedas(N + 1, precio + 1, 1e9);
	bool fin = false;

	for (size_t i = 0; i < N; i++) {

		minMonedas[i][0] = 0;

	}

	for (size_t i = 1; i < N + 1; i++)
	{
		for (size_t j = 1; j < precio + 1; j++) {

			fin = false;
			for (int k = 0; k <= mon[i].cantidad && !fin; k++) {

				if (k*mon[i].valor <= j) {

					if (minMonedas[i][j] > minMonedas[i - 1][j - k*mon[i].valor] + k) {
						minMonedas[i][j] = minMonedas[i - 1][j - k*mon[i].valor] + k;
					}
				}
				else {
					fin = true;
				}
			}
		}
	}

	

	return minMonedas[N][precio];
}



bool resuelveCaso(){


	int N;

	cin >> N;

	if (!cin) return false;

	vector<Monedas> mon(N + 1);

	for (int i = 1; i < N + 1; i++) {

		cin >> mon[i].valor;

	}

	for (int i = 1; i < N + 1; i++) {

		cin >> mon[i].cantidad;

	}

	int precio;

	cin >> precio;

	sort(mon.begin(), mon.end(), compare());

	int minimoMonedas = MinMonedas(mon, N, precio);

	if (minimoMonedas == 1e9)
		cout << "NO" << endl; 
	else
		cout << "SI " << minimoMonedas << endl;

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