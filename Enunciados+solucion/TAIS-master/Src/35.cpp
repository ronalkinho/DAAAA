// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Matriz.h"
#include <vector>

using namespace std;

// patindromo(i,j) = El numero maximo de pato i para forma el patindromo de longitud j
// Caso recursivo:
//			  patindromo(i,j) = patindromo(i+1,j-1)									si letras[i] == letras[j]
//			  patindromo(i,j) = max(patindromo(i+1,j), patindromo(i, j-1)			si letras[i] != letras[j]
// Caso base: 
//			  patindromo(i,i) = 1												una letra sola es el patindromo de longitud 1
// O(n*n) en espacio por uso de matriz de tamano n, siendo n la longitud de la palabra.
// O(n*n/2) en tiempo porque recorremos la mitad de la tabla.
string patindromo(string letras){
	size_t n = letras.size() - 1;

	Matriz<int> pat(n + 1, n + 1, 0);

	for (int i = 1; i <= n-1; i++)
	{
		pat[i][i] = 1;
	}

	for (size_t d = 1; d <= n-1; d++)
	{
		for (size_t i = 1; i <= n-d; i++)
		{
			size_t j = i + d;
			if (letras[i] == letras[j]){
				pat[i][j] = 2 + pat[i + 1][j - 1];
			}
			else {
				pat[i][j] = max(pat[i + 1][j], pat[i][j - 1]);
			}
		}
	}

	int longPatindromo = pat[1][n];
	string patindromo(longPatindromo + 1, ' ');
	int p = 1;
	int q = n;
	int v = 1;
	int w = longPatindromo;
	while (longPatindromo > 0) {
		if (letras[p] == letras[q]){
			patindromo[v] = letras[p];
			patindromo[w] = letras[q];
			longPatindromo -= 2;
			v++;
			w--;
			p++;
			q--;
		}
		else if (longPatindromo == 1){
			patindromo[v] = letras[q];
			longPatindromo--;
		}
		else{
			if (pat[p][q - 1] > pat[p + 1][q]) {
				q--;
			}
			else {
				p++;
			}
		}
	}
	patindromo = patindromo.substr(1, patindromo.size() - 1);
	return patindromo;
}

bool resuelveCaso(){

	string palabra;
	cin >> palabra;

	if (!cin) return false;

	string sol = "";
	if (palabra.size() == 1){
		cout << palabra << endl;
	}
	else {
		palabra = " " + palabra;
		sol = patindromo(palabra);
		cout << sol << endl;
	}

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