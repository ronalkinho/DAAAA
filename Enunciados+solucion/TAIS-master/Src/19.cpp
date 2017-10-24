// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include<iostream>
#include<fstream>


using namespace std;

// O(N), siendo N el numero de agujeros en la manguera
bool resuelveCaso(){

	int nAgujeros; //Numero de agujeros
	int dParche; //Distancia que cubre un parche
	int agujero; //Punto en el que se encuentra un agujero
	int nParches = 1; //Numero de parches necesarios
	int dCubierta = 0; //Distancia que cubre un parche

	cin >> nAgujeros;

	if (!cin) return false;
	else {

		cin >> dParche;
		cin >> agujero;

		dCubierta = agujero + dParche;

		for (int i = 0; i < nAgujeros - 1; i++) {

			cin >> agujero;

			if(dCubierta < agujero) {
				dCubierta = agujero + dParche;
				nParches++;
			}

		}

		cout << nParches << endl;

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