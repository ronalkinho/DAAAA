//  Grupo DA17. Carlos Ballesteros de Andrés
//
//  problem29
//
//  Este problema es una versión del de devolver el cambio y se resuelve
//  de forma muy parecida.
//
//  Consideramos la función recursiva dianas(n, C) que devuelve el mínimo
//  de dardos que hay que tirar para alcanzar la puntuación C en una diana
//  dividida en sectores del 1 al n. Esta función se definiría así.
//
//  dianas(i, j) -> m[i]>j      dianas(i-1, j)
//                  m[i]<=j     min(dianas(i-1, j), dianas(i, j-m[i])+1)
//  donde m[i] es el valor en puntos del sector i.
//  Además los casos base serían dianas(0, j)=INF y dianas(i, 0)= 0.
//
//  Una vez deducido esto podemos pensar en meter los datos en una matriz
//  bidimensional de tamaño n+1 x C+1, la cual se rellena de izquierda a
//  derecha y de arriba a abajo en la que obtenemos el menor número de tiradas.
//  necesarias en la posición m, C
//
//  Para pbtener la solución recorremos la matriz (ya rellena) empezando
//  al revés
//
//
//  El coste de la solución es del orden Θ(nC) tanto en tiempo
//  como en espacio adicional

#include <iostream>
#include "Matriz.h"

using namespace std;

const int INF = 1e9;


//Coste: Θ(nC) tanto en tiempo como en espacio adicional


vector<int> calcular_dianas(vector<int> const& M, int C, int& num) {
    size_t n = M.size() - 1;
    Matriz<int> dianas(n+1, C+1, INF);

    dianas[0][0] = 0;
    // rellenar la matriz
    for (int i = 1; i <= n; ++i) {
        dianas[i][0] = 0;
        for (int j = 1; j <= C; ++j) {
            if (M[i] > j)
                dianas[i][j] = dianas[i-1][j];
            else
                dianas[i][j] = min(dianas[i-1][j], dianas[i][j- M[i]] + 1);
        }
    }
    
    n = M.size() -1;
    vector<int> cuantas(n+1, 0);

    int i = n; int j = C;
    
    while (i >= 1) { // no hemos obtenido el número de tiradas
        if (M[i] <= j && (dianas[i][j] == (dianas[i][j-M[i]])+1)){
            //consideramos una tirada del sector i
            ++cuantas[i];
            j = j - M[i];
            num++;
        }
        else{
            if (M[i] <= j && (dianas[i][j] != dianas[i-1][j])){
                j = j- M[i];
                ++cuantas[i];
                num++;
            }
            --i;
        }
    }
    return cuantas;
}

bool resuelveCaso() {
    int C = 0, S = 0, num = 0;
    
    //LEER DATOS DE ENTRADA
    cin >> C; //Cantidad de puntos
    cin >> S; //Sectores de la diana
    
    vector<int> M(S+1);
    for(int i = 1; i<= S; i++){
        cin >> M[i];
    }
    vector <int> cuantas (S+1, 0);
    
    if (!cin) // fin de la entrada
        return false;
    
    cuantas = calcular_dianas(M, C, num);
    
    //escribir solucion
    if (num == 0)
        cout << "Imposible" << endl;
    else{
        cout << num << ": ";
        for (int i = S; i >= 1; i--){
            for (int j = 0; j < cuantas[i]; j++)
                cout << M[i] << " ";
        }
        cout << endl;
    }
    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}