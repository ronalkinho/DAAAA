//TAIS03 LUIS ARROYO Y ZHIHAO ZHENG

#ifndef PETROLERO_H
#define PETROLERO_H

#include <vector>
#include "Matriz.h"

using namespace std;

class Petrolero {
public:

	// crea una estructura de partición con los elementos 0..N-1, cada uno en un conjunto
	//O(N) siendo N el número de elementos del conjunto
	Petrolero(size_t f, size_t c) : size(f*c), _count(f*c), max(0), id((f + 1)*(c + 1) + 1, -1), malla(f + 1, c + 1) {}

	//  devuelve el identificador del conjunto que contiene a p
	size_t buscar(size_t p) const {
		if (id.at(p) < 0) // es una raíz
			return p;
		else
			return id[p] = int(buscar(id[p]));
	}

	// O(MlogN) siendo M el número de uniones-busquedas y N el número elementos del conjunto
	void unir(size_t p, size_t q) {
		auto i = buscar(p);
		auto j = buscar(q);
		if (i == j) return;
		int tamConjunto = id[i] + id[j];
		if (id[i] < id[j]) { // i es la raíz del mayor árbol
			id[i] += id[j]; id[j] = int(i);
		}
		else {
			id[j] += id[i]; id[i] = int(j);
		}

		if (max < (tamConjunto*-1)) {
			max = (tamConjunto*-1);
		}

		_count--;
	}

	int maximo() {
		return max;
	}

	// O(1) constante
	void ponerMancha(int fila, int col) {

		malla[fila][col] = true;
		if (max == 0){
			max = 1;
		}

		int numCol = malla.numcols();
		int conj = fila * numCol + col;

		// arriba izquierda
		if (malla.posCorrecta(fila - 1, col - 1) && malla[fila - 1][col - 1]) {
			unir(conj, conj - numCol - 1);
		}

		// arriba
		if (malla.posCorrecta(fila - 1, col) && malla[fila - 1][col]) {
			unir(conj, conj - numCol);
		}

		// arriba derecha
		if (malla.posCorrecta(fila - 1, col + 1) && malla[fila - 1][col + 1]) {
			unir(conj, conj - numCol + 1);
		}

		// izquierda
		if (malla.posCorrecta(fila, col - 1) && malla[fila][col - 1]) {
			unir(conj, conj - 1);
		}

		// derecha
		if (malla.posCorrecta(fila, col + 1) && malla[fila][col + 1]) {
			unir(conj, conj + 1);
		}

		// abajo izquierda
		if (malla.posCorrecta(fila + 1, col - 1) && malla[fila + 1][col - 1]) {
			unir(conj, conj + (numCol - 1));
		}

		// abajo
		if (malla.posCorrecta(fila + 1, col) && malla[fila + 1][col]) {
			unir(conj, conj + numCol);
		}

		// abajo derecha
		if (malla.posCorrecta(fila + 1, col + 1) && malla[fila + 1][col + 1]) {
			unir(conj, conj + (numCol + 1));
		}

	}


protected:
	size_t size;             // los elementos son 0 .. size-1
	size_t _count;			// número de conjuntos disjuntos
	size_t max;
	Matriz<bool> malla;
	mutable std::vector<int> id;  // si id[i]>=0 es el padre de i, si no es el tamaño del conjunto de i
};




#endif