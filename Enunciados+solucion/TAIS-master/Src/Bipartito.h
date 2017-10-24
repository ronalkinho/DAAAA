#include "Grafo.h"

using namespace std;

class Bipartito {
private:

public:

	vector<bool> color; // True = Azul - False = Naranja
	vector<bool> marcados;
	bool bipartito;

	Bipartito(Grafo const& grafo) : color(grafo.V(), false), marcados(grafo.V(), false), bipartito(true) {
		for (int i = 0; i < grafo.V(); i++) //Con este for garantizamos que todos los vertices del árbol cumplen que son bipartito
		{
			if (!marcados[i]) { //Con este if mejoramos la complejidad del algoritmo, ya que no volverá a pasar por vertices ya marcados
				color[i] = true;
				dfs(grafo, i);
			}
		}
	}


	bool esBipartito() {

		return bipartito;
	}



protected:

	void dfs(Grafo const& G, size_t v) {
		marcados[v] = true;

		for (auto w : G.adj(v)) {
			if (!this->marcados[w]) {
				color[w] = !color[v]; // Cambio color del adyacente
				dfs(G, w);
			}

			//Si el color del adyacente es igual, entonces el árbol no es bipartito
			if (color[v] == color[w])
			{
				bipartito = false;
			}
		}
	}



};