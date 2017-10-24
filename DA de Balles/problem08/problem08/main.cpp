// Grupo DA17, Carlos Ballesteros de andrés

// Resuelvo el problema con dos colas. Una de máximos con los números menores que la mediana
// y otra de mínimos para los números mayores que la misma.
// Inserto cada número en la cola correspondiente y hago las operaciones correspondientes
// para mantener la estructura equilibrada.


#include <iostream>
#include "PriorityQueue.h"

using namespace std;

// El coste medio de las operaciones en las colas de prioridad implementadas como
// montículos es Log(N), por lo tanto el coste en el caso peor de la solución es
// NLog(N) siendo N el número de elementos que insertamos.

void resolver(int tamano) {
    
    int aux = -1;
    
    
    PriorityQueue <int, greater<int>> colamenores(tamano); //Cola de máximos
    PriorityQueue <int> colamayores(tamano); //Cola de minimos
    
    int mediana = -1;
    int num;
    
    for (int i = 0; i < tamano; i++){
        cin >> num;
        //si es el primer número que se lee, es la mediana;
        if (i == 0){
            mediana = num*2;
            colamenores.push(num);
        }
        else{
            //si el número es menor que la mediana le metemos a la cola de máximos
            if (num*2 < mediana)
                colamenores.push(num);
            else if (num*2 > mediana)
                colamayores.push(num);
            else{
                //Si son iguales la metemos donde menos haya
                if (colamayores.size() >= colamenores.size())
                    colamayores.push(num);
                else
                    colamenores.push(num);
            }
            
            aux = colamayores.size() - colamenores.size();
            
            if (aux > 1){
                colamenores.push (colamayores.top());
                colamayores.pop();
                mediana = (colamayores.top() + colamenores.top());
            }
            else if (aux < -1){
                colamayores.push (colamenores.top());
                colamenores.pop();
                mediana = (colamayores.top() + colamenores.top());
            }
            else if (aux == 1)
                mediana = colamayores.top()*2;
            else if (aux == -1)
                mediana = colamenores.top()*2;
            else if (aux == 0){
                mediana = (colamayores.top() + colamenores.top());
            }
            
            
        }
        cout << mediana << " ";
    }
    cout << endl;
}


int main() {
    int tamano;
    cin >> tamano;
    while (tamano != 0){
        resolver(tamano);
        cin >> tamano;
    }
    return 0;
}