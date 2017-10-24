#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include "PriorityQueue.h"
#include "IndexPQ.h"

using namespace std;

const int INF = 1e9;

void resuelveCaso(int esquiadores) {
	PriorityQueue<int> pers, esq;
	int c, minimo=0;

	for (int i = 0; i < esquiadores; i++){
		cin >> c;
		pers.push(c);
	}
	for (int i = 0; i < esquiadores; i++) {
		cin >> c;
		esq.push(c);
	}

	for (int i = 0; i < esquiadores; i++) {
		minimo += abs(pers.top() - esq.top());
		pers.pop();
		esq.pop();
	}

	cout << minimo << endl;
}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int esquiadores;
	cin >> esquiadores;
	while (esquiadores != 0) {
		resuelveCaso(esquiadores);
		cin >> esquiadores;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}