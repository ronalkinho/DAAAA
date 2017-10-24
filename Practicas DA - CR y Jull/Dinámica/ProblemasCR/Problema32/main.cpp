#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include "PriorityQueue.h"
#include "Matriz.h"
#include "IndexPQ.h"

using namespace std;

const int INF = 1e9;

void printMatriz(Matriz<int> m) {
	for (int i = 0; i < m.numfils(); i++) {
		for (int j = 0; j < m.numcols(); j++)
			if(m[i][j] < 10)
				cout << m[i][j] << "  ";
			else
				cout << m[i][j] << " ";
		cout << endl;
	}

}

void viajes (int p) {
	Matriz<int> coste(p+1, p+1, 0);
	int c;

	for (int i = 1; i <= p-1; ++i) {
		for (int j = i+1; j <= p; ++j) {
			cin >> c;
			coste[i][j] = c;
		}
	}

	//printMatriz(coste);
	//cout << endl << endl;

	for (int i = p; i > 0; --i)
		for (int j = p; j > i; --j)
			for (int z = j-1; z > i; --z)
				coste[i][j] = min(coste[i][j], coste[i][z] + coste[z][j]);
	
	//printMatriz(coste);
	//cout << endl << endl;

	for (int i = 1; i <= p - 1; ++i) {
		for (int j = i + 1; j <= p; ++j)
			cout << coste[i][j] << " ";
		cout << endl;
	}
}

bool resuelveCaso() {
	int poblados;

	cin >> poblados;

	if (!cin)
		return false;

	viajes(poblados);

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
	system("PAUSE");
#endif

	return 0;
}