//  Grupo DA17. Carlos Ballesteros de Andrés
//
//  problem35
//
//  Para resolver este problema parto de la siguiente función recursiva
//  patindromos (i, j) = es el tamaño del máximo palíndromo que se puede
//  obtener de una secuencia de letras P de tamaño N con 0 <= j <= j < N
//  con las letras de la i a la j.
//
//  Esta función puede definirse de forma recursiva de la siguiente manera
//  patindromos(i, j) ->    Si P[i]==P[j]   2+patindromos(i+i, j-1)
//                          Si P[i]!=P[j]   max(patindromos (i+1, j), patindromos (i, j-1))
//
//  Para transformar esta solución a programación dinámica lo que hago es
//  construir una matriz M de NxN elementos (aunque veremos que sólo necesitamos
//  rellenar la mitad superior derecha).
//  La diagonal se rellena con "unos" puesto que obviamente si i = j -> P[i]=P[j]
//  y recorremos la matriz empezando por M[N-2][N-1] y la vamos rellenando con los
//  valores de la fórmula recursiva, de abajo a arriba y de izquierda a derecha.
//
//
//  El coste de la la solución en espacio adicional es del de orden O(N*N),
//  y en tiempo del orden O(N*N/2) puesto que sólo tenemos que rellenar media
//  matriz



#include <iostream>
#include "Matriz.h"

using namespace std;


string calculaPalindromo (string P){
    
    Matriz<int> M(P.size(), P.size(), 0);
    
    //relleno la diagonal a "unos"
    for (int i = 0; i <P.size(); i++)
        M[i][i] = 1;
    
    
    //Rellenamos la matriz, hay que empezar por la esquina inferior derecha.
    for (int i = P.size()-2; i >= 0; i--){
        for (int j = i+1 ; j < P.size(); j++){
            if (P[i]== P[j])
                M[i][j] = M[i+1][j-1] + 2;
            else{
                M[i][j] = max(M[i+1][j], M[i][j-1]);
            }
        }
        
    }
    
    //IMPRIMO LA MATRIZ PARA DEPURAR
    /*for (int i = 0; i < P.size(); i++){
        for (int j = 0; j< P.size(); j++)
            cout << M[i][j] << "   ";
        
        cout << endl;
    }*/
    
    string solucion(M[0][P.size()-1], ' ');
    
    int tam = 0;
    if (M[0][P.size()-1]%2 == 0){
        tam = M[0][P.size()-1]/2;
    }
    else{
        tam = M[0][P.size()-1]/2 + 1;
    }
    
    //OBTENER LA SOLUCIÓN
    int k = 0;                          // Número de letras cogidas hasta el momento
    int x = 0, y = M[0][P.size()-1]-1;  // x e y son indicadores para ver en que punto de la solución estamos
    int i = 0, j = P.size()-1;          // i y j los uso para desplazarme por la matriz
    
    while (k < tam){
        if (P[i]==P[j]){
            solucion[x] = P[i];
            solucion[y] = P[i];
            x++;
            y--;
            k++;
            j--;
            i++;
        }
        else{
            if (M[i][j] <= M[i+1][j])
                i++;
            else
                j--;
        }
    }
    
    return solucion;

}

bool resuelveCaso() {
    string P, solucion;
    
    //LEER DATOS DE ENTRADA
    cin >> P; //Leemos el mensaje
    
    if (!cin) // fin de la entrada
        return false;
    
    solucion =  calculaPalindromo(P);
    
    cout << solucion << endl;
    
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}