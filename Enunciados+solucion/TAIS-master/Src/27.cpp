// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>
#include "Matriz.h"
#include <vector>

using namespace std;


struct Varilla{

	int L;
	int C;

};

void guardaVarillas(vector<Varilla> &varillas){

	for (int i = 1; i < varillas.size(); i++) {
		cin >> varillas[i].L;
		cin >> varillas[i].C;
	}

}
// coste(i, j) = minimo coste de construir varilla de longitud j con i varillas
// caso recursivo: coste(i, j) = min(coste(i - 1, j), coste(i, j - varillas(i).L) + varillas(i).C)		si varillas(i) <= L;
//				   coste(i, j) = coste(i - 1, j)														si variilas(i) > L;
// caso basico:	   coste(i, 0) = 0
//				   coste(0, i) = infinito
// maneras(i, j) = numero de maneras que pueda construir varilla de longitud j con i varillas
// numVarillas(i, j) = minimo numero de varillas i necesarias para construir varilla de longitud j
// O(4n) en espacio por uso de 4 vectores, siendo n el numero de varillas
// O(nL) en tiempo, siendo n el numero de variilas y L la longitud de varilla que desea construir
bool varilla(vector<Varilla> varillas, int L, int &manera, int &numVarilla, int &minCoste){
	int n = varillas.size() - 1;
	int maxL = 1001;
	vector<bool> posible(L + 1, false);
	vector<bool> posibleAux(L + 1, false);
	vector<int> coste(L + 1, 1000000000);
	vector<int> costeAux(L + 1, 1000000000);
	vector<int> maneras(L + 1, 0);
	vector<int> manerasAux(L + 1, 0);
	vector<int> numVarillas(L + 1, maxL);
	vector<int> numVarillasAux(L + 1, maxL);

	posible[0] = true;
	posibleAux[0] = true;
	coste[0] = 0;
	costeAux[0] = 0;
	maneras[0] = 1;
	manerasAux[0] = 1;
	numVarillas[0] = 0;
	numVarillasAux[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = varillas[i].L; j <= L; j++)
		{
			posible[j] = posibleAux[j] || posibleAux[j - varillas[i].L];
			coste[j] = min(costeAux[j], costeAux[j - varillas[i].L] + varillas[i].C);
			maneras[j] = manerasAux[j] + manerasAux[j - varillas[i].L];
			numVarillas[j] = min(numVarillasAux[j], numVarillasAux[j - varillas[i].L] + 1);
		}
		posibleAux = posible;
		costeAux = coste;
		manerasAux = maneras;
		numVarillasAux = numVarillas;
	}
	manera = maneras[L];
	minCoste = coste[L];
	numVarilla = numVarillas[L];
	return posible[L];
}


bool resuelveCaso(){


	int N, L;
	cin >> N >> L;

	if (!cin) return false;

	vector<Varilla> varillas = vector<Varilla>(N + 1);
	guardaVarillas(varillas);

	int coste = 0, maneras = 0, numVarilla = 0;

	bool sol = varilla(varillas, L, maneras, numVarilla, coste);

	if (sol) {
		cout << "SI " << maneras << " " << numVarilla << " "  << coste;
	}
	else {
		cout << "NO";
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