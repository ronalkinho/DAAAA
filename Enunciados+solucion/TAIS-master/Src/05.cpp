#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

long long resuelve(PriorityQueue<long long> pq){
	long long sol = 0;
	while (pq.size() >= 2)
	{
		long long n1, n2, sum = 0;
		n1 = pq.top();
		pq.pop();
		n2 = pq.top();
		pq.pop();
		sum = n1 + n2;
		sol = sol + sum;
		pq.push(sum);
	}
	return sol;
}


// O(n), siendo n el numero de entrada
void leerDatos(PriorityQueue<long long> &pq, int n){
	long long p;

	for (int i = 0; i < n; i++)
	{
		cin >> p;
		pq.push(p);
	}
}

bool resuelveCaso(){
	int n;
	cin >> n;
	if (n == 0)
		return false;


	PriorityQueue<long long> pq;
	leerDatos(pq, n);

	long long sol;
	sol = resuelve(pq);

	cout << sol << endl;

	return true;
}

int main(){

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso()){};

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}