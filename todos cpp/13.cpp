// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#include "GrafoDirigido.h"

// resuelve un caso de prueba
bool resuelveCaso() {
	int dim, caras, serp, escal;
	cin >> dim;
	cin >> caras;
	cin >> serp;
	cin >> escal;
	if (dim == 0 && caras == 0 && serp == 0 && escal == 0) return false;
	else
	{
		GrafoDirigido g(dim*dim);
		for (int i = 0; i < ((dim*dim) - 1); i++) g.ponArista(i, i + 1);
		for (int i = 0; i < serp; i++){
			int a, b;
			cin >> a;
			cin >> b;
			g.ponArista(a - 1, b - 1);
		}
		for (int i = 0; i < escal; i++){
			int a, b;
			cin >> a;
			cin >> b;
			g.ponArista(a - 1, b - 1);
		}
		BreadthFirstDirectedPaths bfdp(g, 0);
		if (bfdp.hasPathTo((dim*dim) - 1)){
			deque<size_t> dq = bfdp.pathTo((dim*dim) - 1);
			cout << (dq.size() / caras) << endl;
		}
		else
			cout << (((dim*dim) - 1) / caras) << endl;
		return true;
	}
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (!cin.eof())
		resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}