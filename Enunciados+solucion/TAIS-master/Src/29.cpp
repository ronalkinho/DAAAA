// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>
#include "Matriz.h"
#include <vector>

using namespace std;

// Diana(i,j) = El numero minimo de dardos i para llegar a una puntuacion j.
// Caso recursivo:
//			  Diana(i,j) = diana(i-1,j)												si puntuaciones(i) > j
//			  Diana(i,j) = min(diana(i-1,j), diana(i, j - puntuaciones(i) + 1)		si puntuaciones(i) <= j
// Caso base: 
//			  Diana(0,j) = infinito.
//			  Diana(i,0) = 0
// Coste en espacio: O(nValor), donde n es el numero de sector de puntuacion de dardos y Valor es el puntuacion que queremos llegar
// Coste en tiempo:  O(nValor)
bool puntos(vector<int> puntuaciones, int valor, int& numDardos, vector<int> &cuales) {

	int n = puntuaciones.size();
	Matriz<unsigned int> dardos(n, valor + 1, INT_MAX);

	for (int i = 1; i < n; i++)
	{
		dardos[i][0] = 0;
		for (int j = 1; j <= valor; j++)
		{
			if (puntuaciones[i] > j){
				dardos[i][j] = dardos[i - 1][j];
			}
			else {
				dardos[i][j] = min(dardos[i - 1][j], dardos[i][j - puntuaciones[i]] + 1);
			}
		}
	}
	
	numDardos = dardos[n-1][valor];
	if (numDardos == INT_MAX){
		return false;
	}
	else {
		int resto = valor;
		int p = n - 1;
		while (resto > 0 && p > 0){
			if (puntuaciones[p] <= resto && dardos[p][resto - puntuaciones[p]] + 1 <= dardos[p - 1][resto]){
				cuales[p]++;
				resto -= puntuaciones[p];
			}
			else {
				p--;
			}
		}
		return true;
	}
}

bool resuelveCaso(){


	int valor, S;
	cin >> valor >> S;

	if (!cin) return false;

	vector<int> puntuaciones(S + 1, -1);
	for (int i = 1; i <= S; i++)
	{
		cin >> puntuaciones[i];
	}

	vector<int> cuales(S + 1, 0);
	int numDardos = 0;
	bool haySol = puntos(puntuaciones, valor, numDardos, cuales);

	if (haySol){
		cout << numDardos << ":";

		for (int i = S; i > 0; i--)
		{
			for (int j = 0; j < cuales[i]; j++){
				cout << " " << puntuaciones[i];
			}
		}
	}
	else {
		cout << "Imposible";
	}
	cout << endl;

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