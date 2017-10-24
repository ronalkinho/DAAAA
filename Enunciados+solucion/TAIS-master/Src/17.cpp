// TAIS03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include "Navegar.h"
using namespace std;

// O(n), siendo n el numero de enlaces
void ponerEnlace(NavegarWeb &web){
	int M;
	cin >> M;
	int v, w, valor;
	for (int i = 0; i < M; i++)
	{
		cin >> v >> w >> valor;
		web.ponerEnlace(v, w, valor);
	}
}

bool resuelveCaso(){
	int N;
	cin >> N;
	if (N == 0)
		return false;
	std::vector<int> vectTiempo;
	int t;
	vectTiempo.push_back(0);
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		vectTiempo.push_back(t);
	}
	NavegarWeb web(N + 1, vectTiempo);

	ponerEnlace(web);

	if (web.esPosible()){
		cout << web.minTiempo() << endl;
	}
	else {
		cout << "IMPOSIBLE" << endl;
	}


	return true;
}

int main(){
#ifndef DOMJUDGE
	std::fstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()){}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}