//  LUIS ARROYO y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <string>
#include "Matriz.h"
using namespace std;

void pintarSol(Matriz<int> const &canoa) {
	int n = canoa.numfils() - 1;

	for (size_t i = 1; i < n; i++)
	{
		cout << canoa[i][i + 1];
		for (size_t j = i + 2; j <= n; j++)
		{
			cout << " " << canoa[i][j];
		}
		cout << endl;
	}
}

void alquiler(Matriz<int> &canoa) {
	int n = canoa.numfils() - 1;

	for (size_t d = 1; d <= n - 1; d++)
	{
		for (size_t i = 1; i <= n - d; i++)
		{
			size_t j = i + d;
			for (size_t k = i; k <= j - 1; k++)
			{
				int temp = canoa[i][k] + canoa[k][j];
				if (temp < canoa[i][j]){
					canoa[i][j] = temp;
				}
			}
		}
	}
}

void matrizPrincipal(Matriz<int> &canoa){
	int n = canoa.numfils() - 1;

	for (size_t i = 1; i <= n; i++)
	{
		canoa[i][i] = 0;
		for (size_t j = i + 1; j <= n; j++)
		{
			cin >> canoa[i][j];
		}
	}
}

// canoa(i,j) = El el coste minimo para llegar al poblado desde i al j
// Caso recursivo:
//					canoa(i,j) = min(canoa(i,j), canoa(i,k) + canoa(k,j))		si i <= j
// Caso base:
//					canoa(i,i) = 0
// O(n*n) en espacio por uso de matriz de tamono n, siendo n el numero de poblado
// O(n*n*n) en tiempo 
bool resuelveCaso() {
	int N;
	cin >> N;

	if (!cin)
		return false;

	Matriz<int> canoa(N + 1, N + 1, -1);

	matrizPrincipal(canoa);

	alquiler(canoa);

	pintarSol(canoa);

	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
