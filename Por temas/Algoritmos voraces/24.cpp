//TAIS04 Fernando Miñambres y Juan José Prieto
//
// El problema se resuelve almacenando en un vector los datos de cada edificio y
// ordenándolos crecientemente por la posicion en la que empiezan y por su tamaño.
// Se asigna un tunel al primer edificio y, posteriormente, se comprueba si puede 
// reutilizarse el tunel del edifios/s anterior/es o es necesario construir uno
// nuevo.
//
//El coste de la función es O(N log N + N) siendo N el número de edificios. 
// El coste O(N log N) corresponde a la operacion sort sobre el vector y el O(N) 
// porque se recorre todo el vector.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;



struct Edificio {
	int oeste;
	int este;
};

bool operator<(Edificio const& a, Edificio const& b) {
	if (a.oeste == b.oeste) {
		return (a.este - a.oeste) < (b.este - b.oeste);
	}
	else {
		return a.oeste < b.oeste;
	}
}


int pasadizos(vector<Edificio> const& ed) {
	int nPas = 1, primerFin = ed[0].este;

	/*	Los pasadizos deben ser de 1 metro de ancho y para ser utiles a un edificio deben estar
	completamente debajo de él cuando lo atraviesan.
	*/
	for (int i = 0; i < ed.size() - 1; i++) {
		if (ed[i + 1].oeste < primerFin) {
			if (primerFin > ed[i + 1].este) {
				//nPas++;
				primerFin = ed[i + 1].este;
			}
		}
		else {
			nPas++;
			primerFin = ed[i + 1].este;
		}
	}

	return nPas;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0)return false;
	vector<Edificio> edificios(N);

	for (int i = 0; i < N; i++) {
		cin >> edificios[i].oeste >> edificios[i].este;
	}
	sort(edificios.begin(), edificios.end(), less<Edificio>());
	cout << pasadizos(edificios) << endl;

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