//TAIS03 LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <vector>
#include "Serpientes.h"
#include "TreeMap_AVL.h"



using namespace std;

//O(V + E), siendo V el número de casillas del tablero y E la relación entre estas
bool resuelveCaso() {
	
	int N, K, S, E;
	
	cin >> N >> K >> S >> E;

	if (N == 0 && K == 0 && S == 0 && E == 0) return false;
	
	int dimension = N*N;

	TreeMap<int, int> serpEsc;

	for (int i = 0; i < S; i++) {		
		int a, b;
		cin >> a >> b;
		serpEsc.insert(a, b);
	}

	for (int j = 0; j < E; j++) {
		int a, b;
		cin >> a >> b;
		serpEsc.insert(a, b);
	}


	Serpientes s(serpEsc, K, dimension);

	cout << s.minimoTiradas() << endl;


	return true;
	
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while(resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}