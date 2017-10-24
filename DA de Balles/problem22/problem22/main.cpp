//
//  Grupo DA17. Carlos Ballesteros de Andrés
//  problem22
//
//  Para la solución de este problema utilizo una cola de mínimos
//  y otra de máximos, para máximizar la diferencia de resultados en
//  los partidos de los broncos.

#include <iostream>
#include "PriorityQueue.h"

using namespace std;

// El coste de la solución es 2*NLog(N) puesto que el coste de las operaciones
// en las colas de prioridad es log(N) y tenemos dos colas. Llamo N al número
// de partidos.

bool resuelveCaso(){
    int partidos= 0, aux = 0, solucion = 0;
    PriorityQueue<int> resultadosRival;
    PriorityQueue<int ,greater<int>> resultadosBroncos;
    
    cin >> partidos;
    
    if (partidos == 0)
        return false;
    
    for(int i = 0; i < partidos; i++){
        cin >> aux;
        resultadosRival.push(aux);
    }
    
    for(int i = 0; i < partidos; i++){
        cin >> aux;
        resultadosBroncos.push(aux);
    }

    while (!resultadosBroncos.empty()){
        if (resultadosRival.top() < resultadosBroncos.top())
            solucion += resultadosBroncos.top() - resultadosRival.top();
        resultadosRival.pop();
        resultadosBroncos.pop();
    }
    
    cout << solucion << endl;
    return true;

}


int main(int argc, const char * argv[]) {
    while (resuelveCaso());
    return 0;
}
