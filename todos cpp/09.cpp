// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
#include <iterator>
#include <functional>
using namespace std;

#include "Grafo.h"

class CC{
private:
	vector<bool> marked;
	vector<int> id;
	int count;

	void dfs(const Grafo &g, const int v){
		marked[v] = true;
		id[v] = count;
		for (int w : g.adj(v)){
			if (!marked[w])
				dfs(g, w);
		}
	}
public:
	CC(const Grafo &g) : marked(g.V()), id(g.V()){
		for (int v = 0; v < g.V(); v++)
		{
			if (!marked[v])
			{
				dfs(g, v);
				count++;
			}
		}
	}

	int getCount(){ return count; }
	int getId(int v){ return id[v]; }
};

void aciclico(const Grafo &g, vector<bool> &marks, const int v, bool &ac, const bool level1, const int ant){
	vector<size_t> adj = g.adj(v);
	vector<size_t>::const_iterator cit = adj.cbegin();
	while (cit != adj.cend() && ac){
		size_t w = *cit;
		if (marks[w] == true){
			if (w != ant)
				ac = false;
		}
		else{
			marks[w] = true;
		}
		cit++;
	}
	cit = adj.cbegin();
	while (cit != adj.cend() && ac)
	{
		size_t w = *cit;
		if (w != ant)
			aciclico(g, marks, w, ac, false, v);
		cit++;
	}
}

// resuelve un caso de prueba
bool resuelveCaso() {
	int nodos;
	cin >> nodos;
	if (!cin) return false;
	int aristas;
	cin >> aristas;
	Grafo g(nodos);
	for (int i = 0; i < aristas; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;
		g.ponArista(a, b);
	}
	CC cc(g);
	bool conexo = true;
	bool esAciclico = true;
	int id = cc.getId(0);
	for (int i = 1; i < g.V() && conexo; i++)
	{
		int id2 = cc.getId(i);
		if (id != id2) conexo = false;
	}
	if (conexo){
		vector<bool> marks(g.V());
		vector<size_t> adj = g.adj(0);
		vector<size_t>::const_iterator cit = adj.cbegin();
		marks[0] = true;
		while (cit != adj.cend() && esAciclico)
		{
			size_t w = *cit;
			aciclico(g, marks, w, esAciclico, true, 0);
			cit++;
		}
	}
	if (conexo && esAciclico) cout << "SI" << endl;
	else cout << "NO" << endl;
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}