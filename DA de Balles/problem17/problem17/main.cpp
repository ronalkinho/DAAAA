// Grupo DA17. Carlos Ballesteros de Andrés
//
// Para resolver este problema se emplea el algoritmo de Dijkstra
//

#include <iostream>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"




using namespace std;
const int INF = 100000;

void relax(AristaDirigida<int> e, IndexPQ<int>&cola, int *distancias, int *tiempos){
    int v = e.from();
    int w = e.to();
    if (distancias[w] > distancias[v] + e.valor() + tiempos[w]){
        distancias[w] = distancias[v] + e.valor() + tiempos[w];
        cola.update(w, distancias[w]);
    }
}

// EL coste de este algoritmo es O(A log V) siendo A el numero de aristas (enlaces entre páginas)
// y V el núero de páginas

bool resuelveCaso(){
    int paginas = 0, enlaces = 0, pag1 = 0, pag2 = 0, coste = 0;
    int actual = 0;
  
    cin >> paginas;
    
    if (paginas == 0)
        return false;
    
    int *tiempos, *distancias;
    GrafoDirigidoValorado<int> grafo(paginas);
    IndexPQ <int> cola (paginas);
    tiempos = new int[paginas];
    distancias = new int [paginas];
    bool visitados[paginas+1];
    
    for (int i = 0; i < paginas; i++){
        cin >> tiempos[i];
    }
    
    cin >> enlaces;
    
    for (int i = 0; i < enlaces; i++){
        cin >> pag1 >> pag2 >> coste;
        AristaDirigida<int> arista(pag1-1, pag2-1, coste);
        grafo.ponArista(arista);
    }
    
    //Algotritmo de Dikjstra;
    
    //Declaraciones necesarias.
    for (int i = 0; i< paginas; i++){
        distancias [i] = INF;
        visitados [i] = false;
    }
    
    distancias[0] = tiempos[0];
    cola.push (0, distancias[0]);
    
    while (!cola.empty()){
        actual = cola.top().elem;
        cola.pop();
        
        if (!visitados[actual]){
            visitados[actual] = true;
            for (AristaDirigida<int> e : grafo.adj(actual))
                relax (e, cola, distancias, tiempos);
        }
    }
    
    
    
    //---------------------//
    
    
    if(distancias[paginas-1] == INF)
        cout << "IMPOSIBLE" << endl;
    else
        cout << distancias[paginas-1] << endl;
    
    delete[] tiempos;
    delete[] distancias;
    
    return true;

}



int main(int argc, const char * argv[]) {

    while (resuelveCaso());
    return 0;
}
