#ifndef PAQUETES_H_
#define PAQUETES_H_

#include <climits>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

class Paquetes{
public:

	Paquetes(int N) : _grafo(N + 1), _costTo(N + 1, INT_MAX), _costBack(N + 1, INT_MAX), _minCost(0), _esPosible(true) {}

	void ponArista(int v, int w, int valor){
		AristaDirigida<int> arista(v, w, valor);
		_grafo.ponArista(arista);
	}

	void recorrerGrafo(int s) {
		dijkstra(s, _costTo);
	}

	void reverse(int s) {
		_grafo = _grafo.reverse();
		dijkstra(s, _costBack);
	}

	void repartir(int w){
		if (_costTo[w] == INT_MAX || _costBack[w] == INT_MAX){
			_esPosible = false;
		}
		else {
			_minCost += _costTo[w] + _costBack[w];
		}
	}

	int minCoste(){
		return _minCost;
	}

	bool posible() {
		return _esPosible;
	}

private:
	GrafoDirigidoValorado<int> _grafo;
	std::vector<int> _costTo;
	std::vector<int> _costBack;
	int _minCost;
	bool _esPosible;

	void dijkstra(int s, std::vector<int> &cost){
		IndexPQ<int> pq(_grafo.V());
		cost[s] = 0;
		pq.push(s, 0);
		while (!pq.empty()) {
			int v; v = pq.top().elem; pq.pop();
			for (auto arista : _grafo.adj(v)){
				int w = arista.to();
				if (cost[w] > cost[v] + arista.valor()){
					cost[w] = cost[v] + arista.valor();
					pq.update(w, cost[w]);
				}
			}
		}
	}

};

#endif