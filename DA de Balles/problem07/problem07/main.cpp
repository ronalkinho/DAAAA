// Grupo DA17, Carlos Ballesteros de andrés

// Para resolver este problema uso una estructura usuario, que almacena los datos
// de la entrada y otra variable que representa el tiempo transcurrido durante la ejecución
// Además se redifine el operador menor, para que en caso de que el tiempo sea igual
// coja primero el de menor id.


#include <iostream>
#include "PriorityQueue.h"

using namespace std;

// El coste medio de las operaciones en las colas de prioridad implementadas como
// montículos es Log(N), por lo tanto el coste en el caso peor de la solución es
// NLog(N) siendo N el número de elementos que insertamos.


typedef struct {
    int id;
    int periodo;
    int tiempo;
}t_usuario;


bool operator < (t_usuario user1, t_usuario user2){
    if (user1.tiempo == user2.tiempo)
        return user1.id < user2.id; //Si tienen el mismo tiempo lo devuelvo por id
    else
        return user1.tiempo < user2.tiempo;
}

void resolver(int numero) {
    PriorityQueue <t_usuario> colaprioridad(numero); //Cola de minimos
    t_usuario aux;
    int k = -1;
    for (int i = 0; i < numero; i++){
        cin >> aux.id;
        cin >> aux.periodo;
        aux.tiempo = aux.periodo;
        colaprioridad.push(aux);
    }
    
    cin >> k;
    
    for (int i = 0; i < k; i++){
        aux = colaprioridad.top();
        colaprioridad.pop();
        cout << aux.id << endl;
        aux.tiempo += aux.periodo;
        colaprioridad.push(aux);
    }
    
    cout << "----" << endl;
    
}


int main() {
    int numero = 0;
    cin >> numero;
    while (numero != 0){
        resolver(numero);
        cin >> numero;
    }
    return 0;
}