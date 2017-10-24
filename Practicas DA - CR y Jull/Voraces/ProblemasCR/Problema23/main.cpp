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

void resuelveCaso() {
	PriorityQueue<int> min;
	PriorityQueue<int, greater<int>> max;
	int v1, v2, pilas, voltaje, num=0, izq, der;

	cin >> pilas >> voltaje;
	for (int i = 0; i < pilas; i++){
		cin >> v1;
		min.push(v1);
		max.push(v1);
	}

	izq = 0; der = pilas - 1;
	while (izq < der) {
		v1 = min.top(); v2 = max.top();
		if (v1 + v2 >= voltaje) {
			num++;
			min.pop(); max.pop();
			izq++; der--;
		}
		else {
			min.pop();
			izq++;
		}
	}
	cout << num << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int casos, e;
	cin >> casos;
	for (int i = 0; i < casos; i++)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}