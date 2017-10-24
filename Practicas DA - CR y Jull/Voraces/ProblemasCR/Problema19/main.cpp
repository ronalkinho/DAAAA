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

void manguera(int agujeros, int L) {
	PriorityQueue<int> p;
	int pos, parches=1, act;

	for (int i = 0; i < agujeros; i++){
		cin >> pos;
		p.push(pos);
	}
	act = p.top()+L;
	p.pop();
	for (int i = 1; i < agujeros; i++){
		if (p.top() > act) {
			act = p.top() + L;
			parches++;
		}
		p.pop();
	}

	cout << parches << endl;
}

bool resuelveCaso() {
	int agujeros, L;

	cin >> agujeros >> L;

	if (!cin)
		return false;

	manguera(agujeros, L);

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