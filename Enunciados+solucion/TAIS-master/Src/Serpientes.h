//TAIS03 LUIS ARROYO Y ZHIHAO ZHENG
#ifndef INVIERTIENDOJAEN_H_
#define INVIERTIENDOJAEN_H_
#include <vector>
#include <queue>
#include "TreeMap_AVL.h"

using namespace std;

class Serpientes {
public:

	// BFS desde un único origen, O(V+E), siendo V el número de casillas del tablero y E la relación entre estas
	Serpientes(TreeMap<int, int> serpEsc, int k, int dimension) : marked(dimension + 1, false), distTo(dimension + 1, 0), fin(dimension) {
		bfs(serpEsc, k);
	}

	size_t minimoTiradas() {
		return distTo[fin];
	}

private:


	vector<size_t> distTo;   // distTo[v] = número de aristas en el camino s-v más corto
	vector<bool> marked;     // marked[v] = hay camino s-v?
	size_t fin;

	//O(V+E), siendo V el número de casillas del tablero y E la relación entre estas
	void bfs(TreeMap<int, int> serpEsc, int k) {
		std::queue<size_t> q;

		bool encontrado = false;
		bool serpOEsc = false;
		
		marked[1] = true;
		q.push(1); // Inicio del tablero

		while (!q.empty() && !encontrado) {
			size_t v = q.front(); q.pop();
			for (size_t i = 1; i <= k && !encontrado; i++) {

				int w;
				if (serpEsc.contains(i + v)) { //Serpientes y escaleras
					w = serpEsc[i + v];
					
					if (!marked[w]) {
						q.push(w);
						distTo[w] = distTo[v] + 1;
						marked[w] = true;
					}

				}
				else { //Dado
					w = i + v;
					
					if (!marked[w]) {
						q.push(w);
						distTo[w] = distTo[v] + 1;
						marked[w] = true;
					}

				}
				
				if (w == fin) {
					encontrado = true;
					
				}
			}
		}
	}





};


#endif