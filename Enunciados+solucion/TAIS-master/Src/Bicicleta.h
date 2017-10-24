// TAIS03, LUIS ARROYO Y ZHIHAO ZHENG
#ifndef BICICLETA_H_
#define BICICLETA_H_

#include <climits>
#include "GrafoValorado.h"
#include "IndexPQ.h"

class Bicicleta{
public:
	Bicicleta(int n) :_grafo(n), _marked(_grafo.V(), false), _distTo(_grafo.V(), INT_MAX), _minEsfuerzo(0), _count(1) {}

	// O(1), constante
	void puente(int v, int w, int valor) {
		Arista<int> arista(v, w, valor);
		_grafo.ponArista(arista);
	}

	// O(n), siendo n el numero de vertices
	int esfuerzo(){
		for (size_t i = 1; i < _grafo.V(); i++)
		{
			_minEsfuerzo += _distTo[i];
		}
		return _minEsfuerzo;
	}

	// O(1), constante
	bool esPosible() {
		bfs(1);
		return _grafo.V() == _count;
	}

private:
	GrafoValorado<int> _grafo;
	std::vector<bool> _marked;
	std::vector<int> _distTo;
	int _minEsfuerzo;
	int _count;

	// O(V+E(logV)), siendo V el numero de vertices y E el numero de aristas
	void bfs(int s) {
		IndexPQ<int> pq(_grafo.V());
		_distTo[s] = 0;
		pq.push(s, 0);
		while (!pq.empty()){
			int v = pq.top().elem; pq.pop();
			_marked[v] = true;
			_count++;
			for (auto arista : _grafo.adj(v)){
				int w = arista.otro(v);
				if (!_marked[w] && _distTo[w] > arista.valor()){
					_distTo[w] = arista.valor();
					pq.update(w,arista.valor());
				}
			}
		}
	}
};
#endif