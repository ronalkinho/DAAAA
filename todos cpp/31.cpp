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

struct Par{
	int a;
	int b;

	Par(int num1, int num2) : a(num1), b(num2) {};
};

// Coste O(n*C) siendo n el numero de sectores y C la puntuacion a alcanzar.
int grados(vector<Par> const& M, int numNodos) {
	size_t n = numNodos;
	Matriz<int> conn(n, n, 0);
	// rellenar la matriz
	for (int i = 0; i < M.size(); i++)
	{
		Par aux = M[i];
		conn[aux.a][aux.b] = 1;
		conn[aux.b][aux.a] = 1;
	}
	if (dardos[n][C] != 999999999)
	{
		int puntRest = C;
		for (int m = n; m >= 1; m--)
		{
			if (dardos[m][puntRest] <= dardos[m - 1][puntRest] && puntRest - M[m-1] >= 0)
			{
				if (dardos[m][puntRest - M[m - 1]] == dardos[m][puntRest] - 1)
				{
					dardosResul.push_back(M[m - 1]);
					puntRest = puntRest - M[m - 1];
					m++;
				}
			}
		}
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
	vector<int> resul;
	int d = diana(punt, valor, resul);
	if (d != 999999999)
	{
		cout << d << ": ";
		for (int i = 0; i < resul.size(); i++)
		{
			cout << resul[i];
			if (i != resul.size() - 1) cout << " ";
		}
		cout << endl;
	}
	else
		cout << "Imposible" << endl;
	return true;
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