//TAIS04 Fernando Miñambres y Juan José Prieto
//
//El problema se resuelve guardando los restaurantes en un vector de tipo Restaurante, ordenadolos
// por la menor posición resultante de restar a la posición del mismo su radio de influencia.
//
//El coste de la función es O(N log N + N) siendo N el número de restaurantes. 
// El coste O(N log N) corresponde a la operacion sort sobre el vector y el O(N) 
// porque se recorre todo el vector.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

struct Restaurante {
	int pos;
	int extrIz;
	int extrDr;
};

bool operator<(Restaurante const& a, Restaurante const& b) {
	if (a.extrIz == b.extrIz) {
		return a.pos < b.pos;
	}
	else {
		return a.extrIz < b.extrIz;
	}
}

int nRestaurantes(vector<Restaurante> const& rest, int L) {

	int restCierre = 0;
	int inicio = rest[0].extrIz;
	int radioFin = rest[0].extrIz;

	if (inicio > 0) return -1;//no cubre desde la posicion 0 de la calle.

	for (int i = 0; i < rest.size(); i++) {
		if (rest[i].extrIz > radioFin)return -1; //hueco

		if (rest[i].extrIz <= inicio) {

			if (rest[i].extrDr > radioFin) {

				if (inicio != radioFin) {

					restCierre++;
					radioFin = rest[i].extrDr;

				}
				else radioFin = rest[i].extrDr;
			}
			else restCierre++;
		}
		else {
			inicio = radioFin;
			i--;
		}
		if (radioFin >= L) {
			restCierre += rest.size() - i - 1; break;
		}
	}
	if (radioFin >= L) {
		return restCierre++;
	}
	else return -1;

}

bool resuelveCaso() {
	int L, N, P, R;
	cin >> L >> N;
	if (!cin)return false;
	if (N != 0) {
		vector<Restaurante> rest(N);
		for (int i = 0; i < N; i++) {
			cin >> P >> R;
			rest[i].pos = P;
			rest[i].extrIz = P - R;
			rest[i].extrDr = P + R;
		}
		sort(rest.begin(), rest.end(), less<Restaurante>());
		cout << nRestaurantes(rest, L) << endl;
	}
	else cout << -1 << endl;

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