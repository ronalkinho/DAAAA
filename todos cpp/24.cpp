// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
#include <queue>
#include <map>
#include "ConjuntosDisjuntos.h"
using namespace std;

struct Edificio{
	int a;
	int b;
	int id;

	Edificio() : a(-1), b(-1), id(-1){};
	Edificio(int puntA, int puntB, int i) : a(puntA), b(puntB), id(i){};
};

bool orden(Edificio const& a, Edificio const& b){ 
	if (a.a < b.a) return true;
	else if (a.a == b.a)
	{
		if (a.b < b.b) return true;
		else return false;
	}
	else return false;
}

// Coste lineal en el numero de edificios.
bool resuelveCaso(const int numEdificios) {
	vector<Edificio> edificios(numEdificios);
	int max = 0;
	for (int i = 0; i < numEdificios; i++){
		int a, b;
		cin >> a;
		cin >> b;
		if (b > max) max = b;
		Edificio in(a, b, i);
		edificios[i] = in;
	}
	sort(edificios.begin(), edificios.end(), orden);
	max = 0;
	int numTuneles = 0;
	for (int i = 0; i < numEdificios; i++){
		Edificio e = edificios[i];
		if (i == 0){
			max = e.b-1;
			numTuneles++;
		}
		else
		{
			if (e.a <= max){
				if (e.b - 1 <= max)
					max = e.b - 1;
			}
			else
			{
				max = e.b-1;
				numTuneles++;
			}
		}
	}
	cout << numTuneles << endl;
	return true;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int edificios;
	cin >> edificios;
	while (edificios != 0){
		resuelveCaso(edificios);
		cin >> edificios;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}