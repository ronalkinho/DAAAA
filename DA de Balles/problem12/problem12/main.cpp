
// Grupo DA17, Carlos Ballesteros de andrés

// -----------------------------------------------------------------------
// Para resolver he interpretado el problema como un grafo en el que un
// número es un vertice y los vecinos son los números a los que se puede
// llegar haciendo las operaciones correspondientes.
// A este grafo se le aplica un algoritmo de búsqueda BFS
// -----------------------------------------------------------------------



#include <iostream>
#include <fstream>
#include <queue>

using namespace std;


// El coste en el caso peor del algoritmo es el de realizar una búsqueda BFS, esto es O(V + E)
// Donde V es el número de vertices (en este caso 10000) y E el de aristas.



bool resuelveCaso(){
    
    // Declaramos e inicializamos los elementos necesarios para el bfs,
    // es decir, la cola y el array de distancias y marcados.
    queue <int> cola;
    int distancias[10000];
    bool marcados[10000];
    
    for (int i = 0; i < 10000; i++){
        distancias[i] = 0;
        marcados[i] = false;
    }
    
    int ini, dest, aux;
    bool encontrado = false;
    cin >> ini;
    cin >> dest;
    
    if (!cin)
        return false;
    
    //Ponemos el númer inicial como marcado y le ponemos el primero de la cola
    marcados[ini] = true;
    cola.push(ini);
    
    while (!cola.empty() && !encontrado){
        aux = cola.front();
        cola.pop();
        
        if (aux == dest)
            encontrado = true;
        
        //Hacemos las operaciones pertinentes.
        if (marcados[(aux+1)%10000] == false){
            cola.push((aux+1)%10000);
            marcados[(aux+1)%10000] = true;
            distancias[(aux+1)%10000] = distancias[aux] + 1;
        }
        
        if (marcados[(aux*2)%10000] == false){
            cola.push((aux*2)%10000);
            marcados[(aux*2)%10000] = true;
            distancias[(aux*2)%10000] = distancias[aux] + 1;
        }
        
        if (marcados[(aux/3)%10000] == false){
            cola.push((aux/3)%10000);
            marcados[(aux/3)%10000] = true;
            distancias[(aux/3)%10000] = distancias[aux] + 1;
        }
    }
    
    cout << distancias[dest] << endl;
    
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


