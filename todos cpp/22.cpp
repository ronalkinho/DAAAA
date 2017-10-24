// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

bool orden(int const& a, int const& b){ return a > b; }

// Coste lineal en el numero de partidos jugados.
bool resuelveCaso(int partidos) {
	vector<int> rivales(partidos);
	vector<int> locales(partidos);
	for (int i = 0; i < partidos; i++){
		int aux;
		cin >> aux;
		rivales[i] = aux;
	}
	for (int i = 0; i < partidos; i++){
		int aux;
		cin >> aux;
		locales[i] = aux;
	}
	sort(rivales.begin(), rivales.end(), orden);
	sort(locales.begin(), locales.end());
	int maxExito = 0;
	for (int i = 0; i < partidos; i++){
		int rival = rivales[i];
		int local = locales[i];
		if (rival < local)
		{
			int diferencia = local - rival;
			maxExito = maxExito + diferencia;
		}
	}
	cout << maxExito << endl;
	return true;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	
	int partidos;
	cin >> partidos;
	while (partidos != 0)
	{
		resuelveCaso(partidos);
		cin >> partidos;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}