//TAIS04 Fernando Miñambres y Juan José Prieto
//
// El problema se resuelve utilizando una matriz para caluclar recursivamente
// el numero letras que pueden formar un palíndromo desde i hasta j. Siendo:
//
// Para todo j >= i
// Matriz[i][j] = 1;                                        Si i = j;
// Matriz[i][j] = Matriz[i + 1][j - 1] + 2;                 Si la letra i es igual
// 																a la letra j.
// Matriz[i][j] = max(Matriz[i + 1][j], Matriz[i][j - 1]);  En otro caso
//
// Despues se recorre la solucion cogiendo Matriz[i][j] si la letra i es igual a
// la letra j o recorriendo la matriz por el mayor numero entre Matriz[i][j - 1] 
// y [i + 1][j].
//
//El coste de la función es de O(n*n) en tiempo y O(n*n) en espacio adicional, siendo
// n el numero de letras que forman la palabra inicial.
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
string calculaPalindromoMayor(string palabra) {
	int n = palabra.length();
	Matriz<int> longuitudPalindromos(n, n, 0);

	for (int i = 0; i < n; i++)
		longuitudPalindromos[i][i] = 1;

	for (size_t d = 1; d < n; ++d) { // recorre diagonales
		for (size_t i = 0; i < n - d; ++i) { // recorre elementos de diagonal
			size_t j = i + d;
			if (palabra[i] == palabra[j]) {
				longuitudPalindromos[i][j] = longuitudPalindromos[i + 1][j - 1] + 2;
			}
			else {
				longuitudPalindromos[i][j] = max(longuitudPalindromos[i + 1][j], longuitudPalindromos[i][j - 1]);
			}
		}
	}

	int max = longuitudPalindromos[0][n - 1];
	string resultado(max, '\0');

	int j = n - 1, i = 0, pos = 0;
	while (pos * 2 < max) {
		if (max - (pos * 2) == 1) {
			resultado[pos] = palabra[j];
			pos++;
			i++;
			j--;
		}
		else {
			if (palabra[i] == palabra[j]) {
				resultado[pos] = palabra[j];
				resultado[max - pos - 1] = palabra[j];
				pos++;
				i++;
				j--;
			}
			else if (longuitudPalindromos[i][j - 1] <= longuitudPalindromos[i + 1][j]) {
				i++;
			}
			else {
				j--;
			}
		}
	}

	return resultado;
}

bool resuelveCaso() {
	string palabra;
	cin >> palabra;
	if (!cin)
		return false;

	cout << calculaPalindromoMayor(palabra) << endl;

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