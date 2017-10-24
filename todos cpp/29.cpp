// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

#include "Matriz.h"

int diana(vector<int> const& M, int C) {
	size_t n = M.size() - 1;
	Matriz<int> dardos(n + 1, C + 1, 999999999);
	vector<int> dardosFinal(M.size());
	dardos[0][0] = 0;
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		dardos[i][0] = 0;
		for (int j = 1; j <= C; ++j) {
			if (M[i] > j)
				dardos[i][j] = dardos[i-1][j];
			else
				dardos[i][j] = min(dardos[i-1][j], dardos[i][j - M[i]] + 1);
		}
	}
	if (dardos[n][C] != 999999999)
	{

	}
	return dardos[n][C];
}

// resuelve un caso de prueba
bool resuelveCaso() {
	int valor;
	cin >> valor;
	if (!cin) return false;
	int sectores;
	cin >> sectores;
	vector<int> punt(sectores);
	for (int i = 0; i < sectores; i++)
	{
		cin >> punt[i];
	}
	int d = diana(punt, valor);
	if (d != 999999999)
		cout << diana(punt, valor) << endl;
	else
		cout << "Imposible" << endl;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (!cin.eof())
		resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}