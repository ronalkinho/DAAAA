// Grupo DA17, Carlos Ballesteros de Andrés

// Solamente he utilizado la función resuelvecaso que hace la lectura, resuelve el problema y escribe la solución
// Para ello lo que utilizo es un árbo de busqueda avl que almacena para cada clave (número de capítulo) su "fecha de emisión"
// así que para cada capítulo se comprueba si ha sido ya emitido y en función de eso se actualiza la cuenta de los días desde
// la última emisión de un capítulo repetido.

#include <iostream>
#include <stdio.h>
#include "TreeMap_AVL.h"

using namespace std;

// El coste del algoritmo de resolución en el caso peor es f(n(log(n)))
// puesto que el coste de las operaciones en árboles de busqueda es log(n)
// y las tenemos que repetir n veces. Siendo n el número de capítulos.

void resuelveCaso() {
    int num = 0, dias = 0, cap = 0, maxdias = 1, ultrep  = 0;
    TreeMap <int, int> map;
    cin >> num;
    for (int i = 0; i< num; i++){
        cin >> cap;
        if (!map.contains(cap)){
            dias ++;
            map.insert(cap, i);
            if (dias > maxdias)
                maxdias = dias;
        }
        else{
            if (map.at(cap) >= ultrep){
                ultrep = map.at(cap);
                dias = i - ultrep;
                if (i - map.at(cap) > maxdias)
                    maxdias = i - map.at(cap);
                map.insert (cap, i);
            }
            else{
                dias ++;
                map.insert(cap, i);
                if (dias > maxdias)
                    maxdias = dias;
            }
        }
    }
    cout << maxdias << endl;
}



int main() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}