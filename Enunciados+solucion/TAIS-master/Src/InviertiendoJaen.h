#ifndef INVIERTIENDOJAEN_H_
#define INVIERTIENDOJAEN_H_
#include "Matriz.h"
using namespace std;


class Jaen{
public:
	Jaen(size_t f, size_t c) : size(f*c), _count(f*c), numEle(f*c, 1), id(f*c, -1), _matriz(f, c), max(0) {};

	void ponerParcela(int f, int c){
		_matriz[f][c] = true;
		int col = _matriz.numcols();

		if (max == 0){
			numEle[f*col + c] = 1;
			max = 1;
		}

		if (c > 0 && _matriz[f][c - 1] == true){
			unir((f * col + c), (f * col + c - 1));
		}
		if (f > 0 && _matriz[f - 1][c] == true){
			unir((f * col + c), ((f - 1) * col + c));
		}
	}

	int maxParcela(){
		return max;
	}

	// devuelve el número de conjuntos disjuntos
	size_t count() const { return _count; }

	//  devuelve el identificador del conjunto que contiene a p
	size_t buscar(size_t p) const {
		if (id.at(p) < 0) // es una raíz
			return p;
		else
			return id[p] = int(buscar(id[p]));
	}

protected:
	// unir los conjuntos que contengan a p y q
	void unir(size_t p, size_t q) {
		auto i = buscar(p);
		auto j = buscar(q);
		if (i == j) return;
		if (id[i] < id[j]) { // i es la raíz del mayor árbol
			id[i] += id[j]; id[j] = int(i);
			numEle[i] += numEle[j];
			if (numEle[i] > max){
				max = numEle[i];
			}
		}
		else {
			id[j] += id[i]; id[i] = int(j);
			numEle[j] += numEle[i];
			if (numEle[j] > max){
				max = numEle[j];
			}
		}
		_count--;
	}

	size_t size;             // los elementos son 0 .. size-1
	size_t _count;           // número de conjuntos disjuntos
	std::vector<int> numEle;
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i

	Matriz<bool> _matriz;
	int max;
};
#endif