// TAIS03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include "Bicicleta.h"
using namespace std;

//O(n) siendo n el numero de aristas
void ponerPuente(Bicicleta &bici){
	int P;
	cin >> P;
	int v, w, valor;
	for (int i = 0; i < P; i++) {
		cin >> v >> w >> valor;
		bici.puente(v, w, valor);
	}
}

bool resuelveCaso(){
	int I;
	cin >> I;
	if (!cin)
		return false;

	Bicicleta bici(I + 1);
	ponerPuente(bici);
	if (bici.esPosible()){
		cout << bici.esfuerzo() << endl;
	}
	else {
		cout << "No hay puentes suficientes" << endl;
	}

	return true;
}

int main(){
#ifndef DOMJUDGE
	std::fstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso()){}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
}