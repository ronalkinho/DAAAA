// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Matriz.h"
#include "TreeMap_AVL.h"
#include <vector>

using namespace std;


/*
forma(i) = Siendo i el número de posibilidades de codificar un codigo
Caso recursivo:
				forma(i) =  forma(i + 1),   si mensaje(i) es código
						   +forma(i + 2),   si mensaje(i, i+1] es código
						   +forma(i + 3),   si mensaje(i, i+1, i+2] es código

Caso base:
				forma(m) = 1, siendo m el número de códigos

Coste en espacio: O(m), siendo m el número de códigos
Coste en tiempo: O(m)
*/


int decodificar(TreeMap<int, int>  &codigo, string &mensaje) {

	int m = mensaje.size() - 1;

	vector<int> forma(m + 2);
	forma[m + 1] = 1;
	int temp;

	for (int i = m; i >= 0; i--)
	{
		temp = mensaje[i] - '0';
		if (codigo[temp]){
			forma[i] = forma[i + 1] % 1000000007;
		}

		if (temp != 0) {
			if (i + 1 <= m){
				int n = mensaje[i + 1] - '0';
				temp = temp * 10 + n;
				if (codigo[temp]){
					forma[i] = (forma[i] + forma[i + 2]) % 1000000007;
				}
			}
			if (i + 2 <= m){
				int n = mensaje[i + 2] - '0';
				temp = temp * 10 + n;
				if (codigo[temp]){
					forma[i] = (forma[i] + forma[i + 3]) % 1000000007;
				}
			}
		}
		else {
			forma[i] = forma[i + 1] % 1000000007;;
		}
	}
	
	return forma[0];
}

bool resuelveCaso(){

	int N;
	cin >> N;

	if (N == 0) return false;

	TreeMap<int, int> codigo;
	for (size_t i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		codigo.insert(n, n);
	}

	string mensaje;
	cin >> mensaje;

	int numMensaje;
	
	numMensaje = decodificar(codigo, mensaje);

	cout << numMensaje << endl;

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