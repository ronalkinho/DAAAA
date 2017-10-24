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

#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

class SP{
private:
	vector<AristaDirigida<int>> edgeTo;
	vector<int> distTo;
	IndexPQ<int> pq;

	void relax(const AristaDirigida<int> &e, const vector<int> &costes){
		int v = e.from();
		int w = e.to();
		if (distTo[w] > distTo[v] + e.valor() + costes[w])
		{
			distTo[w] = distTo[v] + e.valor() + costes[w];
			edgeTo[w] = e;
			pq.update(w, distTo[w]);
		}
	}
public:
	SP(const GrafoDirigidoValorado<int> &g, int s, const vector<int> &costes) : edgeTo(g.V()), distTo(g.V(), 1000000000), pq(g.V()){
		distTo[s] = 0;
		pq.push(s, 0);
		while (!pq.empty())
		{
			int v = pq.top().elem;
			pq.pop();
			for (AristaDirigida<int> e : g.adj(v))
				relax(e, costes);
		}
	}

	int tiempo(int coste, int paginas){
		int sol = distTo[paginas - 1];
		if (sol >= 1000000000)
			return 0;
		else
			return sol + coste;
	}
};

// Coste E log V, siendo E el nº de aristas (enlaces) y V el nº de vertices (paginas).
// resuelve un caso de prueba
void resuelveCaso(int paginas) {
	vector<int> costes(paginas);
	for (int i = 0; i < paginas; i++)
		cin >> costes[i];
	int enlaces;
	cin >> enlaces;
	GrafoDirigidoValorado<int> grafo(paginas);
	for (int i = 0; i < enlaces; i++)
	{
		int pag1, pag2, tiempo;
		cin >> pag1;
		cin >> pag2;
		cin >> tiempo;
		AristaDirigida<int> edge(pag1 - 1, pag2 - 1, tiempo);
		grafo.ponArista(edge);
	}
	SP sol(grafo, 0, costes);
	int tiempo = sol.tiempo(costes[0], paginas);
	if (tiempo > 0) cout << tiempo << endl;
	else cout << "IMPOSIBLE" << endl;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int paginas;
	cin >> paginas;
	while (paginas != 0)
	{
		resuelveCaso(paginas);
		cin >> paginas;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}