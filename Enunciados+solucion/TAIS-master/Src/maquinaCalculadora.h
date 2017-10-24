// TAIS03 LUIS ARROYO Y ZHIHAO ZHENG
#ifndef MAQUINACALCULADORA_H_
#define MAQUINACALCULADORA_H_

#include "GrafoDirigido.h"
using namespace std;

class GrafoCal{
public:

	// Constructor
	GrafoCal(int n, int m) : o(n), d(m), marked(10000, false), distTo(10000){
		bfs(o);
	}

	// O(1)
	int menorPulsacion(){
		return distTo[d];
	}


private:
	std::vector<bool> marked;     // marked[v] = hay camino s-v?
	std::vector<size_t> distTo;   // distTo[v] = número de aristas en el camino s-v más corto

	// O(V+E), siendo V el numero de vertices y E numero de aristas
	void bfs(int s) {
		bool encontrado = false;
		std::queue<size_t> q;
		marked[s] = true;
		q.push(s);
		while (!q.empty() && !encontrado) {
			size_t v = q.front(); q.pop();
			for (size_t i = 0; i < 3 && !encontrado; i++)
			{
				int w;
				switch (i)
				{
				case 0:
					w = (v + 1) % 10000;
					break;
				case 1:
					w = (v * 2) % 10000;
					break;
				case 2:
					if (v != 0)
						w = (v / 3) % 10000;
					else
						w = 0;
					break;
				default:
					break;
				}
				if (!marked[w]) {
					q.push(w);
					marked[w] = true;
					distTo[w] = distTo[v] + 1;
					if (w == d){
						encontrado = true;
						break;
					}
				}
			}
		}
	}

	int o;
	int d;
};
#endif