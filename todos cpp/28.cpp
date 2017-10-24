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

#include "Matriz.h"

struct Cofre{
	int prof;
	int valor;
	Cofre(){}
	Cofre(int p, int v) : prof(p), valor(v){}
};

// Coste O(n*M) siendo n el numero de cofres y M los segundos que puede estar debajo del agua.
void tesoro(vector<Cofre> const & cofres, int M,
	int & valor, vector<bool> & cuales) {
	size_t n = cofres.size() - 1;
	Matriz<int> mochila(n + 1, M + 1, 0);
	// rellenar la matriz
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (cofres[i].prof > j)
				mochila[i][j] = mochila[i - 1][j];
			else
				mochila[i][j] = max(mochila[i - 1][j],
				mochila[i - 1][j - cofres[i].prof] + cofres[i].valor);
		}
	}
	valor = mochila[n][M];
	// cálculo de los objetos
	int resto = M;
	for (size_t i = n; i >= 1; --i) {
		if (mochila[i][resto] == mochila[i - 1][resto]) {
			// no cogemos objeto i
			cuales[i] = false;
		}
		else { // sí cogemos objeto i
			cuales[i] = true;
			resto = resto - cofres[i].prof;
		}
	}
}

// resuelve un caso de prueba
bool resuelveCaso() {
	int cap, numCofres;
	cin >> cap;
	if (!cin) return false;
	cin >> numCofres;
	vector<Cofre> cofres(numCofres+1);
	for (int i = 1; i <= numCofres; i++)
	{
		int prof, v;
		cin >> prof;
		cin >> v;
		Cofre c(prof * 3, v);
		cofres[i] = c;
	}
	vector<bool> cuales(numCofres+1, false);
	int oroMaximo = 0;
	tesoro(cofres, cap, oroMaximo, cuales);
	cout << oroMaximo << endl;
	int cofresCogidos = 0;
	vector<Cofre> cofresFinal;
	for (int i = 1; i <= numCofres; i++)
	{
		if (cuales[i])
		{
			cofresFinal.push_back(cofres[i]);
			cofresCogidos++;
		}
	}
	cout << cofresCogidos << endl;;
	for (int i = 0; i < cofresCogidos; i++)
	{
		cout << cofresFinal[i].prof / 3 << " ";
		cout << cofresFinal[i].valor << endl;
	}
	cout << "----" << endl;
	return true;
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