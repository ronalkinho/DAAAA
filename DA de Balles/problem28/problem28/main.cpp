//  Grupo DA17. Carlos Ballesteros de Andrés
//
//  problem28
//
//  Para solucionar este problema, muy similar al de la mochila, partimos de la
//  función recursiva  cofres(i, j) que devuelve el máximo valor que podemos obtener
//  considerando los cofres del 1 al i y contando con j segundos disponibles.
//  Esta función recursiva se especificaría así:
//
//  cofres(i, j) -> p[i]>j      cofres(i-1, j)
//                  p[i]<=j     max(cofres(i-1, j), cofres(i-1, j-p[i]) + v[i])
//  Siendo p[i] los segundos que penalizamos al coger un cofre y v[i] el valor del mismo.
//  Y teniendo como casos base
//  cofres (0, j) = 0 y cofres(j, 0) = 0.
//
//  Esta función la transformamos en una matriz bidimiensional de tamaño n+1 x M+1
//  siendo n el número de cofres que consideramos y M el máximo de segundos que permite
//  la bombona. Y que se recorre de izquierda a derecha y de arriba a abajo.
//
//  Una vez tenemos esta matriz rellena, para obtener la solución recorremos la matriz de nuevo
//  y vamos almacenando en un vector los cofres que hemos escogido.
//
//
//  El coste de la solucón es deO(nM) tanto en tiempo como en espacio adicional,
//  siendo n el número de cofres y M el número de segundos.


#include <iostream>
#include "Matriz.h"

using namespace std;



void cofres_pd(vector<int> const& P, vector<int> const& V, int M, int& valor, vector<bool> & cuales, int& cogidos) {
    size_t n = P.size() - 1;
    
    Matriz<int> solucion(n+1, M+1, 0);
    // rellenar la matriz
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= M; ++j) {
            if ((P[i]+2*P[i]) > j)
                solucion[i][j] = solucion[i-1][j];
            else
                solucion[i][j] = max(solucion[i-1][j],solucion[i-1][j - (P[i]+2*P[i])] + V[i]);
        }
    }
    valor = solucion[n][M];
    
    
    // cálculo de los objetos
    int resto = M;
    for (size_t i = n; i >= 1; --i) {
        if (solucion[i][resto] == solucion[i-1][resto]) {
            // no cogemos objeto i
            cuales[i] = false;
        } else { // sí cogemos objeto i
            cuales[i] = true;
            cogidos++;
            resto = resto - (P[i]+2*P[i]);
        }
    }
}



bool resuelveCaso() {
    int M = 0, cofres = 0, valor = 0, cogidos = 0;

    //LEER DATOS DE ENTRADA
    cin >> M; //Segundos que permite la bombona
    cin >> cofres;
    vector<int> P (cofres+1);
    vector<int> V (cofres+1);
    vector<bool> cuales(cofres+1);
    
    for(int i = 1; i<= cofres; i++){
        cin >> P[i];
        cin >> V[i];
    }
    
    if (!cin) // fin de la entrada
        return false;
    
    
    cofres_pd(P, V, M, valor, cuales, cogidos);
    
    //escribir solucion
    
    cout << valor << endl;
    cout << cogidos << endl;
    for (int i = 1; i<=cofres ; i++){
        if (cuales[i]){
            cout << P[i] << " ";
            cout << V[i] << endl;
        }
    }
    cout << "----" << endl;
    
    
    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}