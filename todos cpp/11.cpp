// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <map>
using namespace std;

#include "Grafo.h"

void dfs(Grafo g, int v, bool marked[], int id[], int count){
	marked[v] = true;
	id[count]++;
	for (int w : g.adj(v)){
		if (!marked[w])
			dfs(g, w, marked, id, count);
	}
}

int CC(Grafo g){
	bool marked[20000];
	int id[20000];
	int count = 0;
	for (int v = 0; v < g.V(); v++){
		if (!marked[v])
		{
			dfs(g, v, marked, id, count);
			count++;
		}
	}
	int max = 0;
	for (int i = 0; i <= count; i++){
		if (max < id[i])
			max = id[i];
	}
	return max;
}

// resuelve un caso de prueba
void resuelveCaso() {
	int amigos, pares;
	cin >> amigos;
	cin >> pares;
	Grafo grafo(amigos);
	for (int i = 0; i < pares; i++){
		int amigo1, amigo2;
		cin >> amigo1;
		cin >> amigo2;
		grafo.ponArista(amigo1, amigo2);
	}
	int sol = CC(grafo);
	cout << sol << endl;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	std::cin >> casos;
	cin.get();
	for (int i = 0; i < casos; i++){
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}