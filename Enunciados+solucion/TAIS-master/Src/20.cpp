#include<iostream>
#include<fstream>
#include"PriorityQueue.h"


using namespace std;


bool resuelveCaso(){

	int N;

	cin >> N;

	if (!cin) return false;
	
	PriorityQueue<int, greater<int>> pq(N);

	int p;

	for (size_t i = 0; i < N; i++) {
		cin >> p;
		pq.push(p);
	}

	int descuento = 0;
	int precio = 0;

	for (size_t i = 1; i <= N; i++) {

		precio = pq.top(); pq.pop();
		if (i % 3 == 0)
			descuento += precio;

	}
	

	cout << descuento << endl;


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