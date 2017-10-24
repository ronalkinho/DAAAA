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
using namespace std;

#include "GrafoDirigido.h"

// resuelve un caso de prueba
bool resuelveCaso() {
	int aguj, longParches;
	cin >> aguj;
	if (!cin) return false;
	cin >> longParches;
	vector<int> v;
	int numParches = -1;
	for (int i = 0; i < aguj; i++)
	{
		int agujero;
		cin >> agujero;
		if (numParches >= 0)
		{
			if (agujero > (v[numParches] + longParches)){
				v.push_back(agujero);
				numParches++;
			}
		}
		else{
			v.push_back(agujero);
			numParches++;
		}
	}
	cout << numParches + 1 << endl;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (!cin.eof())
		resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}