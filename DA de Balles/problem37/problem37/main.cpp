//  Grupo DA17. Carlos Ballesteros de Andrés
//  problem37
//
//
//  Para resolver este problema utilizo una matriz de números combinatorios
//  que calculo una vez al principio de la ejecución.
//  De esta forma tengo una matriz C, la cual guarda en C[i][j] el resultado de
//  combinatorio(i sobre j).Además a la vez que calculo esta ya relleno el vector
//  de soluciones V, el cual devuelve para cada V[n] el
//  número de resultados posibles para n caracoles. Ambas, tanto matriz de combinatorios
//  como vector de resultado se calculan para 1000 caracoles.
//
//  la función recursiva quedaría así
//  Caracoles (n)  ->   n = 0      = 1
//                      n > 0      = sumatorio desde j = 1 hasta n
//                                  { Combinatorio(n sobre j) * caracoles(n-j) }
//
//  Al saber que el máximo de caracoles que participan es 1000 el coste tanto en
//  tiempo de ejecución como en espacio adicional es constante en O (1).
//  independientemente del número de soluciones que queramos calcular.


#include <iostream>
#include "Matriz.h"

using namespace std;

const int modulo = 46337;

bool resuelveCaso(Matriz <int> &C, vector <int> &V) {
    int n = 0, solucion = 0;
    
    //LEER DATOS DE ENTRADA
    cin >> n; //Cantidad de caracoles

    if (!cin) // fin de la entrada
        return false;
    
    solucion = V[n];
    
    //escribir solucion

    cout << solucion << endl;
    
    return true;
}


int main() {
    
    // Calculo la matriz de números combinatorios, como el máximo de caracoles es 1000
    // pongo ese tamaño. A la vez calculo el vector de resultados, tambieén para ese
    // tamaño.
    
    Matriz<int> C(1001,1001,0);
    vector <int> V(1001, 0);
    
    V[0] = 1;
    C[0][0] = 1;
    for (int i = 1; i <= 1000; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= 1000; ++j) {
            C[i][j] = ((C[i-1][j-1] + C[i-1][j])%modulo);
            V[i] = (V[i]+((C[i][j]* V[i-j])%modulo))%modulo;
        }
    }

    while (resuelveCaso(C, V));
    
    return 0;
}