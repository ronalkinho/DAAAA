// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <vector>

using namespace std;


struct Tesoro{

	int P;
	int M;

};

void guardaTesoro(vector<Tesoro> &tes){

	for (int i = 1; i < tes.size(); i++) {
		cin >> tes[i].P;
		cin >> tes[i].M;
	}

}

// Tesoro(i, j) = NºMaximo de monedas antes de llegar a j(o igual) siendo j la profundidad y de 0 a i el numero de tesoros que se encuentra en la profundidad
//Caso recursivo:
//					tes(k) --> Siendo "tes" la lista de tesoros y k el número total de tesoros. Donde tes(k-1).p es la profundida donde se encuentra el tesoro y tes(k-1).m el numero de monedas que contiene el tesoro
//					Tesoro(i,j) = tesoro(i-1, j),    si (tes(i).p + tes(i).p * 2) > j || tesoro(i-1, j) > (tesoro(i - 1, j - tes(i).p + tes(i).p * 2)) + tes(i).m
//					Tesoro(i, j) = tesoro(i - 1, j - (tes(i).p + tes(i).p * 2)) + tes(i).m,    si esoro(i-1, j) <= (tesoro(i - 1, j - tes(i).p + tes(i).p * 2)) + tes(i).m
//
//Caso base:
//					Tesoro(0, j) = 0
//					Tesoro(i, 0) = 0
//Coste en espacio: O(NT), siendo N el número de cofres encontrado y T los segundos que la botella permite estar debajo del agua
//Coste en tiempo:  O(NT)
void tesoro(vector<Tesoro> tes, int N, int T, int &monedas, vector<Tesoro> &cuales, int &cont) {

	Matriz<int> tesoro(N + 1, T + 1, 0);


	//Construyo matriz (tabla)
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= T; j++) {
			if ((tes[i].P) + (tes[i].P * 2) > j) {
				tesoro[i][j] = tesoro[i - 1][j];
			}
			else {
				if (tesoro[i - 1][j] > tesoro[i - 1][j - (tes[i].P + tes[i].P * 2)] + tes[i].M) {
					tesoro[i][j] = tesoro[i - 1][j];
				}
				else
					tesoro[i][j] = tesoro[i - 1][j - (tes[i].P + tes[i].P * 2)] + tes[i].M;
			}

		}
	}

	monedas = tesoro[N][T];

	int resto = T;
	for (int i = N; i >= 1; i--){
		if (tesoro[i][resto] != tesoro[i - 1][resto]) {
			cuales[i] = tes[i];
			resto = resto - (tes[i].P + tes[i].P * 2);
			cont++;
		}
	}

}


bool resuelveCaso(){


	int N, T;
	cin >> T >> N;

	if (!cin) return false;

	vector<Tesoro> tes = vector<Tesoro>(N + 1);
	guardaTesoro(tes);

	int monedas = 0;
	vector<Tesoro> cuales = vector<Tesoro>(N + 1);
	int cont = 0;

	for (int i = 0; i <= N; i++) {
		cuales[i].P = -1;
		cuales[i].M = -1;
	}

	tesoro(tes, N, T, monedas, cuales, cont);


	cout << monedas << endl;
	cout << cont << endl;
https://drive.google.com/drive/u/1/folders/0B48jwsPTway2VUdMc1kxNGw3Rmc
	for (int i = 1; i <= N; i++) {

		if (cuales[i].M >= 0)
			cout << cuales[i].P << " " << cuales[i].M << endl;
	}

	cout << "----" << endl;


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