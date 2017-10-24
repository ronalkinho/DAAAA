#include <iostream>
#include <fstream>
#include "Paquetes.h"
using namespace std;

void construirGrafo(Paquetes &paquetes){
	int C, v, w, valor;
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> v >> w >> valor;
		paquetes.ponArista(v, w, valor);
	}
}

bool resuelveCaso(){
	int N;
	cin >> N;
	if (!cin)
		return false;

	Paquetes paquetes(N);
	construirGrafo(paquetes);


	int O, P, w;
	cin >> O >> P;
	paquetes.recorrerGrafo(O);
	paquetes.reverse(O);

	for (int i = 0; i < P; i++)
	{
		cin >> w;
		paquetes.repartir(w);
	}
	if (paquetes.posible()){
		cout << paquetes.minCoste() << endl;
	}
	else {
		cout << "Imposible" << endl;
	}

	return true;
}

int main(){
#ifndef DOMJUDGE
	std::fstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}