#include <iostream>
#include <fstream>
#include <string>
#include "InviertiendoJaen.h"
using namespace std;

void construir(Jaen &jaen, int f, int c){
	cin.ignore();
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char c;
			cin.get(c);
			if (c == '#'){
				jaen.ponerParcela(i, j);
			}
		}
		cin.ignore();
	}
}

bool resuelveCaso(){
	int F, C;
	cin >> F >> C;
	if (!cin)
		return false;

	Jaen jaen(F, C);
	construir(jaen, F, C);

	cout << jaen.maxParcela() << endl;

	return true;
}

int main(){
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso()){}
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
}