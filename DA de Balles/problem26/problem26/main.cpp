//
//  Grupo DA17. Carlos Ballesteros de Andrés
//  problem26
//
//  Para solucionar este ejercicio meto los edificios en una cola, ordenados
//  por el punto de la calle en el que empiezan, y en caso de empate por tamaño de mayor a menor

#include <iostream>
#include "PriorityQueue.h"

using namespace std;

// El coste de la solución es NLog(N) puesto que el coste de las operaciones
// en las colas de prioridad es log(N) Llamo N al número
// de restaurantes.

typedef struct{
    int posicion;
    int principio;
    int final;
}tRestaurante;

bool operator<(tRestaurante r1, tRestaurante r2){
    if (r1.principio == r2.principio)
        return (r1.final-r1.principio) > (r2.final-r2.principio);
    else
        return r1.principio < r2.principio;
}

bool resuelveCaso(){
    int restaurantes=0, longitud = 0, radio = 0, act = 0, anterior = 0, res = 0;
    
    PriorityQueue<tRestaurante> colaRestaurantes;
    tRestaurante aux;
    
    cin >> longitud;
    cin >> restaurantes;
    anterior = -longitud - 1;
    if (!cin)
        return false;
    
    for (int i = 0; i < restaurantes; i++){
        cin >> aux.posicion;
        cin >> radio;
        aux.principio = aux.posicion-radio;
        aux.final = aux.posicion+radio;
        colaRestaurantes.push(aux);
    }
    
    while (!colaRestaurantes.empty() && act < longitud) {
        aux = colaRestaurantes.top();
        colaRestaurantes.pop();
        if (aux.principio <= act) {
            if (aux.principio <= anterior && aux.final > act) {
                act = aux.final;
            }
            else if (aux.principio > anterior && aux.final > act) {
                anterior = act;
                act = aux.final;
                res++;
            }
        }
        
    }

    

    if (act < longitud)
        cout << -1 << endl;
    else
        cout << restaurantes - res << endl;

    return true;
    
}


int main(int argc, const char * argv[]) {
    while (resuelveCaso());
    return 0;
}