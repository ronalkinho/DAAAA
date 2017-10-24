// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Matriz.h"
#include <vector>

using namespace std;

// caracol(i) = El numero marcadores diferentes que pueda finalizar la carrera con i caracoles
// Caso recursivo:
//			  caracol(i) = SUM( Comb(i,j) * caracol(i-j) )	 para toda j,  1 <= j <= i
// Caso base: 
//			  Diana(1) = 1
// O(N*N) en tiempo siendo N el numero de caracoles
// O(1001*1001) en espacio por uso de matriz de combinatoria
void caracol(vector<long long int> &vCaracol, Matriz<long long int> matrizComb) {
	long long int sol = 0;
	int i = 1000;
	vCaracol[0] = 1;
	for (int j = 1; j <= i; j++)
	{
		long long int solParcial = 1;
		for (int k = 1; k <= j; k++)
		{
			vCaracol[j] = (matrizComb[j][k] * vCaracol[j - k] + vCaracol[j]) % 46337;
		}
	}
}

void preprocesarMatriz(Matriz<long long int> &matrizComb) {

	int N = 1000;
	matrizComb[0][0] = 1;
	for (size_t i = 1; i <= N; i++)
	{
		matrizComb[i][0] = 1;
		for (size_t j = 1; j <= N; j++)
		{
			matrizComb[i][j] = (matrizComb[i - 1][j - 1] + matrizComb[i - 1][j]) % 46337;
		}
	}
}

bool resuelveCaso(vector<long long int> &vCaracol, Matriz<long long int> &matrizComb){

	int N;
	cin >> N;

	if (!cin) return false;

	long long int sol = vCaracol[N];

	cout << sol << endl;

	return true;
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	Matriz<long long int> matrizComb(1001, 1001, 0);
	vector<long long int> vCaracol(1001);

	preprocesarMatriz(matrizComb);
	caracol(vCaracol, matrizComb);

	while (resuelveCaso(vCaracol, matrizComb));

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}