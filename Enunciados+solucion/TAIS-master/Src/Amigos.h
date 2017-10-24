// TAIS03, LUIS ARROYO Y ZHIHAO ZHENG
#include "Grafo.h"

using namespace std;

class Amigos {
private:

	vector<bool> marcados;
	int cont;
	int max;

public:


	// O(V+E), siendo V el numero de vertices y E el numero de aristas
	Amigos(Grafo const& grafo) : cont(0), marcados(grafo.V(), false), max(0) {
		//Buscamos los diferentes grupos de amigos que pudiese haber dentro del grafo
		for (unsigned i = 0; i < grafo.V(); i++)
		{
			if (!marcados[i]) {

				dfs(grafo, i);

				if (cont > max) max = cont;

				cont = 0;
			}
		}
	}

	// O(1), constante
	int maxAmigos() {

		return max;
	}



protected:

	// O(E), siendo E el numero de aristas
	void dfs(Grafo const& G, size_t v) {
		marcados[v] = true;
		cont++;
		for (auto w : G.adj(v)) {
			if (!this->marcados[w]) {
				dfs(G, w);
			}
		}
	}



};