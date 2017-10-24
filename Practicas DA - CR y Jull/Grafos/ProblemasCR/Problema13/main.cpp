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

void serpientesEscaleras(int N, int caras, int serp, int esca) {
	int v1, v2, v = 1, w;
	vector<bool> marked((N*N) + 1, false);
	vector<int> distTo((N*N) + 1, INF);
	queue<int> q;
	map<int, int> atajos;

	for (int i = 0; i < serp + esca; ++i) {
		cin >> v1 >> v2;
		atajos.insert(std::pair<int, int>(v1, v2));
	}

	marked[v] = true;
	distTo[v] = 0;
	q.push(v);
	while (v != N*N) {
		v = q.front();
		q.pop();
		for (int i = 1; i <= caras; ++i) {
			w = v + i;
			if (w <= N*N) {
				if (atajos.find(w) != atajos.end())//En el caso de que este w tenga atajo desde v podría llegar hasta el atajo, 
					w = atajos[w];					//no hasta w solo, por eso sustituyo
				if (!marked[w]) {
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}
			}
		}
	}

	cout << distTo[N*N] << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int N, caras, serp, esca;
	cin >> N >> caras >> serp >> esca;
	while (N != 0) {
		serpientesEscaleras(N, caras, serp, esca);
		cin >> N >> caras >> serp >> esca;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}