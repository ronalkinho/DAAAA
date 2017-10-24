// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

// O(NlogN), siendo N el numero de edificios(entre 1 y 100000)
bool resuelveCaso(){

	int N;
	cin >> N;

	if (N == 0) return false;

	PriorityQueue<int> esquiadores;
	PriorityQueue<int>	esquis;
	int p;
	for (int i = 0; i < N; i++)
	{
		cin >> p;
		esquiadores.push(p);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> p;
		esquis.push(p);
	}

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += abs(esquiadores.top() - esquis.top());
		esquiadores.pop();
		esquis.pop();
	}

	cout << sum << endl;

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
	system("pause");
#endif

	return 0;
}