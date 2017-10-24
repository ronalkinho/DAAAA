// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema mediante la idea recursiva que sigue:

caracoles (i) = será el número de resultados posibles en los que pueden 
				quedar i caracoles

caracoles(i) = sumatorio desde j=1 hasta i de : ( i ) * caracoles (i-j)
												  j

*/												  

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include "IndexPQ.h"
#include "Matriz.h"

using namespace std;

const int INF = 1000000000;
const int MOD = 46337;

Matriz<int> C(1001, 1001, 0);
vector<int> res(1001, 0);

void combinatorios() {

	C[0][0] = 1;
	for (int i = 1; i <= 1000; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= 1000; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
}

void resultados() {

	res[0] = 1;
	for (int i = 1; i <= 1000; ++i)
		for (int j = 1; j <= i; ++j)
			res[i] = (res[i] + C[i][j] * res[i - j]) % MOD;
}

bool resuelveCaso() {
	int caracoles;

	cin >> caracoles;

	if (!cin)
		return false;

	cout << res[caracoles] << endl;

	return true;
}

/*
Para resolver el probema nos valemos de una matriz de 1001x1001 números en la cual se guardarán todos 
los números combinatorios de desde 1 hasta 1000 y por otro lado calcularemos en un vector de enteros
todos los resutados posibles desde 0 hasta 1000 caracoles.
Esto lo hacemos puesto que la diferencia entre un caso y otro únicamente es el número de caracoles, no
hay ningún dato más que condicione el resultado, por tanto lo que hacemos es calcular todos los resultados
posibles para los 1000 posibles caracoles que habrá como máximo, de esta manera la solución al problema
es constante.

Coste en tiempo: es del O(1) debido a que tanto las funciones de calcular los números combinatorios y la de
los resultados son constantes, no hay entrada que haga variar su tiempo de ejecución, por otro lado devolver
la solución simplemente es una consulta a ese vector de resutados, lo que también es constante.
Coste en espacio: el espacio quererido es de 1001*1001 elementos enteros para la matriz y un vector de 1001
elementos enteros para los resultados, en total 1001^2*4 + 1001*4 bytes
*/
int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	combinatorios();
	resultados();

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}