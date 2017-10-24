// TAIS04 Fernando Miñambres y Juan José Prieto
//
// El problema se resuelve utilizando una matriz para calcular recursivamente 
// las combinaciones de i sobre j, siendo:
// Para todo j <= i:
// Matriz[i][j] = 0.          Si j == 0
// Matriz[i][j] = Matriz[i - 1][j - 1] + Matriz[i - 1][j];  En otro caso.
//
// Mientras calculamos esta matriz utilizamos la solucion de cada i, j para ir 
// calculando recursivamente la solucion final en un vector, siendo;
// Vector[i] = Vector[i] + Matriz[i][j] * Vector[i - j];
//
// Finalmente tendremos la solucion para n caracoles en Vector[n].
//
// El coste de la función es de O(n^2) en tiempo y O(n^2 + n) en espacio adicional,
// siendo n = 1000, ya que se calcula al iniciar para 1000 caracoles y cada llamada
// a resuelveCaso tendrá O(1).
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
vector<long long int> calculaFinalesPosibles(int numeroDeCaracoles) {
	Matriz<long long int> combinaciones(numeroDeCaracoles + 1, numeroDeCaracoles + 1, 0);

	vector<long long int> solucion(numeroDeCaracoles + 1, 0);
	solucion[0] = 1;
	combinaciones[0][0] = 1;
	for (int i = 1; i <= numeroDeCaracoles; i++) {
		combinaciones[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			long long int combo = (combinaciones[i - 1][j - 1] + combinaciones[i - 1][j]) % 46337;
			combinaciones[i][j] = combo;
			solucion[i] = (solucion[i] + combo * solucion[i - j]) % 46337;
		}
	}

	return solucion;
}

bool resuelveCaso(vector<long long int> const &solucion) {
	int numeroDeCaracoles;
	cin >> numeroDeCaracoles;
	if (!cin)
		return false;

	cout << solucion[numeroDeCaracoles] << endl;

	return true;
}



int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	vector<long long int> solucion = calculaFinalesPosibles(1000);

	while (resuelveCaso(solucion)) {

	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}