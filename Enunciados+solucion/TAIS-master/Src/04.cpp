// TAIS03 LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "TreeMap_AVL.h"
using namespace std;

// O(n), siendo n numero de de entrada(capitulos emitidos)
void construirArbol(TreeMap<int, int> &treemap, int &sol){
	int n;
	int p;
	int pos = 0;
	int cont = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		if (treemap.contains(p) && treemap.at(p) >= pos){ // repite
			cont = i - pos;
			pos = treemap.at(p) + 1;
			if (cont > sol)
				sol = cont;
		}
		treemap.insert(p, i);
	}
	if (n - pos > sol)
		sol = n - pos;
}

void resuelveCaso(){
	int sol = 0, p;
	TreeMap<int, int> treemap;
	construirArbol(treemap, sol);

	//sol = resuelve(treemap, p);

	cout << sol << endl;
}

int main(){

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCaso;
	cin >> numCaso;
	for (int i = 0; i < numCaso; i++)
	{
		resuelveCaso();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}