//
//  GrupoAmigos.h
//  problem11
//
//  Created by Carlos Ballesteros on 21/11/16.
//  Copyright © 2016 Carlos Ballesteros. All rights reserved.
//

#ifndef GrupoAmigos_h
#define GrupoAmigos_h

#include "ConjuntosDisjuntos.h"

class GrupoAmigos : public ConjuntosDisjuntos {

public:
    GrupoAmigos(size_t N) : ConjuntosDisjuntos(N) {}
    int size(size_t p) const {
        return -id[buscar(p)];
    }
};



#endif /* GrupoAmigos_h */
