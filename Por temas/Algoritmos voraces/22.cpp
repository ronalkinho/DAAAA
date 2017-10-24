//TAIS04 Fernando Miñambres y Juan José Prieto
//
// El problema se resuelve almacenando los puntos de cada equipo en un vector, en el que los puntos de los rivales
// se ordena de menor a mayor y el de los Broncos de mayor a menos. Se comprueba si los puntos de los Broncos son mayores que 
// los de los rivales y si es así se guarda la diferencia de puntos.
//
//El coste de la función es O( 2(N log N) + N) siendo N el número de partidos. El coste O( 2(N log N) ) corresponde a las
// operaciones sort sobre los vectores y el O(N) porque se recorre uno de los vectores.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int exito(vector<int> riv, vector<int> bro) {
	int exitoMax = 0;
	sort(riv.begin(), riv.end(), less<int>());
	sort(bro.begin(), bro.end(), greater<int>());

	for (int i = 0; i < bro.size(); i++) {
		if (bro[i] > riv[i]) {
			exitoMax += (bro[i] - riv[i]);
		}
	}
	return exitoMax;
}


bool resuelveCaso() {
	int nPartidos;
	cin >> nPartidos;
	if (nPartidos == 0) return false;

	vector<int> rivales(nPartidos);
	vector<int> broncos(nPartidos);

	for (int i = 0; i < rivales.size(); i++) {
		cin >> rivales[i];
	}
	for (int j = 0; j < broncos.size(); j++) {
		cin >> broncos[j];
	}

	cout << exito(rivales, broncos) << endl;
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