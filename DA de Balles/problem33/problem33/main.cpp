//  Grupo DA17. Carlos Ballesteros de Andrés
//
//  problem33
//
//
//  Para solucionar este problema utilizo una versión del algoritmo de caminos
//  minimos de Floyd.
//
//  Partimos de una matriz de adyacencia G en la cual el valor G[i][i] puede
//  tomar tres valores:
//  0   si  i=j
//  1   si  hay arista de i a j
//  INF si  no hay conexión de i a j
//
//  Esa misma matriz la aprovechamos para rellenar con los valores del algoritmo
//  partiendo de la siguiente función recursiva.
//
//  Ck(i, j): Coste mínimo para ir de i a j pudiendo utilizar los nodos intermedios
//  entre i y k.
//  Ck ¡(i, j) se define como:
//  min (Ck-1(i, j), Ck-1(i, k) + Ck-1(k, j))
//  Es decir para ir de i a j tomamos el camino que cueste menos entre pasar por k
//  o ir directamente.
//  Los casos bases los tenemos en el supuesto de que k = 0
//  C0(i, j)    =   G[i][j] si i != j
//                  0       si i = j
//
//
//  El coste en tiempo de ejecución es O(V^3) puesto que tenemos tres bucles for anidados.
//  Es coste en espacio adicional es O(V^2) puesto que sólo utilizamos una matriz
//  de tamaño VxV
//  V es el número de vertices del problema.



#include <unordered_map>
#include <iostream>
#include "Matriz.h"



using namespace std;

const int INF = 1e9;

int Floyd(Matriz<int>& G) {
    size_t n = G.numfils() - 1;
    int max = 0;
    
    if (n == 1)
        return 0;
    
    // actualizaciones de la matriz
    for (size_t k = 1; k <= n; ++k){
        for (size_t i = 1; i <= n; ++i){
            for (size_t j = 1; j <= n; ++j) {
                int temp = G[i][k] + G[k][j];
                if (temp <= G[i][j]) { // es mejor pasar por k
                    G[i][j] = temp;
                }
            }
        }
    }

    for (size_t i = 1; i <= n; ++i){
        for (size_t j = i; j <= n; ++j) {
            if (G[i][j] > max)
                max = G[i][j];
        }
    }
    
    return max;
}



bool resuelveCaso() {
    
    unordered_map<string, int> personas;
    string nombre1, nombre2;
    int contador = 1, i, j;
    pair <string, int> aux;
    int solucion = 0;
    
    size_t V;
    cin >> V;
    
    if (!cin)
        return false;
    
    size_t E;
    cin >> E;
    
    Matriz<int> grafo(V+1,V+1,INF);
    
    if (V > 1)
    {
        for (size_t k = 1; k <= E; ++k) { // leer aristas
            cin >> nombre1;
            if (personas.find(nombre1) == personas.cend()){//Si no está lo insertamos
                pair <string, int> aux(nombre1, contador);
                personas.insert(aux);
                contador ++;
            }
    
            cin >> nombre2;
            if (personas.find(nombre2) == personas.cend()){//Si no está lo insertamos
                pair <string, int> aux(nombre2, contador);
                personas.insert(aux);
                contador ++;
            }
        
            i = personas.at(nombre1);
            j = personas.at(nombre2);
    
            grafo[i][j] = 1;
            grafo[j][i] = 1;
            grafo[j][j] = 0;
            grafo[i][i] = 0;
        }
    }
    /*
    //Imprimo la matriz para depurar
    cout << endl;
    for(int i = 0; i< V; i++){
        for (int j = 0; j < V; j++){
            if(grafo[i][j]== INF)
                cout << "INF" << " ";
            else
                cout << grafo[i][j] << " ";
        }
        cout << endl;
    }*/

    solucion = Floyd(grafo);
    
    if (solucion != INF)
        cout << solucion << endl;
    else
        cout << "DESCONECTADA" << endl;
  
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}