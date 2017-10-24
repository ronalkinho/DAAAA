es un //
//  Grupo DA17. Carlos Ballesteros de Andrés
//  problem24
//
//  Para solucionar este ejercicio meto los edificios en una cola, ordenados
//  por su extremo final, y voy sacando y viendo que se puedan conectar
//  entre ellos

#include <iostream>
#include "PriorityQueue.h"

using namespace std;

// El coste de la solución es NLog(N) puesto que el coste de las operaciones
// en las colas de prioridad es log(N) Llamo N al número
// de edificios.

typedef struct{
    int principio;
    int final;
}tEdificio;

bool operator<(tEdificio e1, tEdificio e2){
    return e1.final < e2.final;
}

bool resuelveCaso(){
    int edificios=0, solucion = 1;
    PriorityQueue<tEdificio> colaEdificios;
    tEdificio eAux, eAux2;
    
    cin >> edificios;
    
    if (edificios == 0)
        return false;
    
    for (int i = 0; i < edificios; i++){
        cin >> eAux.principio;
        cin >> eAux.final;
        colaEdificios.push(eAux);
    }
    
    eAux = colaEdificios.top();
    colaEdificios.pop();
    
    while (!colaEdificios.empty()){
        eAux2 = colaEdificios.top();
        if (eAux2.principio >= eAux.final){
            solucion ++;
            eAux = eAux2;
        }
        colaEdificios.pop();
    }
    
    cout << solucion << endl;
    return true;
    
}


int main(int argc, const char * argv[]) {
    while (resuelveCaso());
    return 0;
}