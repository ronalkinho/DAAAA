// Grupo DA17, Carlos Ballesteros de andrés

// -----------------------------------------------------------------------
// Para solucionar este problema he utilizado el algoritmo de Kruskal,
// He extendido la funcionalidad de la clase ConjuntosDisjuntos añadiendo
// la función que devuelve el tamaño, para comprobar que en el conjunto
// estén todas las islas conectadas.
// -----------------------------------------------------------------------

#include <iostream>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

class ConjuntoIslas : public ConjuntosDisjuntos {
    
public:
    ConjuntoIslas(size_t N) : ConjuntosDisjuntos(N) {}
    
    int size(size_t p) const {
        return -id[buscar(p)];
    }
    
};


// -----------------------------------------------------------------------
// El coste de resolver el coste es de 0(m log n) siendo m el número de
// aristas y n el número de islas (Coste del Algoritmo de Kruskal)
// -----------------------------------------------------------------------
bool resuelveCaso(){
    int islas = 0, puentes = 0, i1 = 0, i2 = 0, coste = 0, v = 0, w = 0, total = 0;
    int aux1 = 0, aux2 = 0;
    PriorityQueue<Arista<int>> cola;
    
    cin >> islas;
    cin >> puentes;
    
    ConjuntoIslas conjunto(islas + 1);
    
    for (int i=0; i<puentes; i++){
        cin >> i1 >> i2 >> coste;
        Arista<int> arista (i1, i2, coste);
        cola.push(arista);
    }
    
    if (!cin)
        return false;
    
    int contador = 0;
    
    while (!cola.empty() && contador < islas-1){
        
        Arista<int> arista = cola.top();
        cola.pop();
        
        v = arista.uno();
        w = arista.otro(v);

        aux1 = conjunto.buscar(v);
        aux2 = conjunto.buscar(w);

        if (aux1 != aux2){
            total += arista.valor();
            contador ++;
            conjunto.unir(v, w);
        }
    }
    
            
    if (conjunto.size(v) == islas)
        cout << total << endl;
    else
        cout << "No hay puentes suficientes" << endl;


    return true;
}

int main(int argc, const char * argv[]) {
    /*    #ifndef DOMJUDGE
     std::ifstream in("casos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf());
     #endif */
    
    while (resuelveCaso());
    
    /*   #ifndef DOMJUDGE
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif */
    
    return 0;
}
