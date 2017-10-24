#ifndef CONJDISJ_H_
#define CONJDISJ_H_

#include "ConjuntosDisjuntos.h"

class ConjDisj : public ConjuntosDisjuntos {
public:
	ConjDisj(size_t N) : ConjuntosDisjuntos(N) {}
	int size(size_t p) const {
		return -id[buscar(p)];
	}
};

#endif