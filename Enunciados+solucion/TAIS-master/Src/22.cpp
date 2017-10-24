// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include<iostream>
#include<fstream>
#include "PriorityQueue.h"

using namespace std;

// O(2 * NlogN), siendo N el numero de artidos pronosticados(entre 1 y 1000)
bool resuelveCaso(){

	int n;
	cin >> n;

	if (n == 0) return false;
	

	PriorityQueue<int> colaRival;
	PriorityQueue<int, std::greater_equal<int>> colaBroncos;

	int p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		colaRival.push(p);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> p;
		colaBroncos.push(p);
	}

	int acuExito = 0;
	for (int i = 0; i < n; i++)
	{
		if (colaBroncos.top() > colaRival.top())
			acuExito += colaBroncos.top() - colaRival.top();

		colaRival.pop();
		colaBroncos.pop();
	}

	cout << acuExito << endl;

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