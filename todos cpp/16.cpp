// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

#include "GrafoValorado.h"
#include "IndexPQ.h"

class PrimMST{
private:
	vector<Arista<int>> edgeTo;
	vector<int> distTo;
	vector<bool> marked;
	IndexPQ<int> pq;

	void visit(const GrafoValorado<int>& g, int v)
	{
		marked[v] = true;
		for (Arista<int> e : g.adj(v))
		{
			int w = e.otro(v);
			if (marked[w]) continue;
			if (e.valor() < distTo[w])
			{
				edgeTo[w] = e;
				distTo[w] = e.valor();
				pq.update(w, distTo[w]);
			}
		}
	}

public:

	PrimMST(const GrafoValorado<int>& g) : edgeTo(g.V()), distTo(g.V(), 1000000000), marked(g.V(), false), pq(g.V()){
		distTo[0] = 0;
		pq.push(0, 0);
		while (!pq.empty())
		{
			int top = pq.top().elem;
			pq.pop();
			visit(g, top);
		}
	}

	vector<Arista<int>> getEdgeTo(){ return edgeTo; }
	vector<bool> getMarks(){ return marked; }
	vector<int> getDist(){ return distTo; }
};

// resuelve un caso de prueba
bool resuelveCaso() {
	int islas, puentes;
	cin >> islas;
	if (!cin) return false;
	cin >> puentes;
	GrafoValorado<int> grafo(islas);
	for (int i = 0; i < puentes; i++)
	{
		int isla1, isla2, coste;
		cin >> isla1;
		cin >> isla2;
		cin >> coste;
		Arista<int> arista(isla1 - 1, isla2 - 1, coste);
		grafo.ponArista(arista);
	}
	PrimMST mst(grafo);
	vector<bool> marks = mst.getMarks();
	vector<bool>::const_iterator cit = marks.cbegin();
	vector<int> dist = mst.getDist();
	vector<int>::const_iterator citDist = dist.cbegin();
	bool recorrido = true;
	int coste = 0;
	while (cit != marks.cend() && recorrido)
	{
		bool marked = *cit;
		if (marked)
		{
			coste = coste + *citDist;
		}
		else
			recorrido = false;
		cit++; citDist++;
	}
	if (recorrido)
		cout << coste << endl;
	else
		cout << "No hay puentes suficientes" << endl;
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