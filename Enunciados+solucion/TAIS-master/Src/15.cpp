//TAIS03 LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include "Petrolero.h"

using namespace std;


//O(F*C), siendo F numero de fila y C numero de columna
void creaPetroleo(int fila, int col, Petrolero &p) {

	char car;
	cin.ignore();
	for (int f = 1; f <= fila; f++) {
		for (int c = 1; c <= col; c++) {

			cin.get(car);
			if (car == '#') {
				p.ponerMancha(f, c);

			}
		}

		cin.ignore();
	}

}

bool resuelveCaso() {

	int f, c;

	cin >> f >> c;

	if (!cin) return false;

	Petrolero p(f,c);

	creaPetroleo(f, c, p);


	cout << p.maximo();

	int nueva;
	cin >> nueva;

	for (int i = 0; i < nueva; i++)
	{
		cin >> f >> c;
		p.ponerMancha(f,c);
		cout << " " << p.maximo();
	}

	cout << endl;

	return true;
}

int main() {

#ifndef DOMJUDGE
	ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}