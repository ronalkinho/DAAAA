
// Grupo DA17, Carlos Ballesteros de andrés

// ------------------------------------------------------------------------
// Para resolver este problema he planteado el problema como un grafo
// en el que las personas son vertices y las relaciones de amistad
// que existen entre ellas aristas. He creado la clase GrupoAmigos de
// la forma indicada por el profesor para que herede de ConjuntosDisjuntos
// y añada un método que devuelve el tamaño de una estructura de partición.
// ------------------------------------------------------------------------



#include <iostream>
#include "ConjuntosDisjuntos.h"

using namespace std;



class GrupoAmigos : public ConjuntosDisjuntos {
    
    public:
        GrupoAmigos(size_t N) : ConjuntosDisjuntos(N) {}
    
        int size(size_t p) const {
            return -id[buscar(p)];
        }

};



// El coste de la solución del problema es lineal del algoritmo respecto al
// número de aristas O(N), puesto que las operaciones con la clase ConjuntosDisjuntos
// tienen un coste constante. Como ya se ha dicho las aristas son las relaciones de
// amistad entre dos personas.


void resolver (){
    
    int vertices, aristas, max = 1, per1, per2;
    cin >> vertices;
    cin >> aristas;
    GrupoAmigos conj(vertices + 1);
    
    for (int i = 0; i < aristas; i++){
        cin >> per1;
        cin >> per2;
        conj.unir(per1, per2);
        if (conj.size(per1) > max)
            max = conj.size(per1);
    }
    
    cout << max << endl;

}

int main(int argc, const char * argv[]) {
    int casos = 0;
    cin >> casos;
    for (int i = 0; i < casos; i++){
        resolver ();
    }
    return 0;
}


