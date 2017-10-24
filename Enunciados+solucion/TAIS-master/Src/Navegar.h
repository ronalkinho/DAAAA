// TAIS03, LUIS ARROYO Y ZHIHAO ZHENG
#ifndef NAVEGAR_H_
#define NAVEGAR_H_

#include <vector>
#include <climits>
#include <queue>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

class NavegarWeb{
public:
	NavegarWeb(int n, std::vector<int> tiempo) : _grafo(n), _tiempoCarga(tiempo), _tiempoTo(_grafo.V(), INT_MAX), cont(1) {}

	// O(1), constante
	void ponerEnlace(int v, int w, int valor) {
		AristaDirigida<int> arista(v, w, valor);
		_grafo.ponArista(arista);
	}

	// O(1), constante
	int minTiempo(){
		return _tiempoTo[_grafo.V() - 1];
	}

	bool esPosible(){
		bfs(1);
		return _tiempoTo[_grafo.V()-1] != INT_MAX;
	}

private:
	GrafoDirigidoValorado<int> _grafo;
	std::vector<int> _tiempoCarga;
	std::vector<int> _tiempoTo;
	int cont;

	// O(E*log(V)), siendo V el numero de  paginas manejadas, y E numero de enlaces * (V-1)
	void bfs(int s){
		IndexPQ<int> pq(_grafo.V());
		_tiempoTo[s] = _tiempoCarga[s];
		pq.push(s, 0);
		while (!pq.empty()){
			int v; v = pq.top().elem; pq.pop();
			cont++;
			for (auto arista : _grafo.adj(v)){
				int w = arista.to();
				if (_tiempoTo[w] > (_tiempoTo[v] + arista.valor() + _tiempoCarga[w])){
					_tiempoTo[w] = _tiempoTo[v] + arista.valor() + _tiempoCarga[w];
					pq.update(w, _tiempoTo[v] + arista.valor() + _tiempoCarga[w]);
				}
			}
		}
	}
};
#endif