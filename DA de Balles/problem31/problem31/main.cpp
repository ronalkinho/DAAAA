//  Grupo DA17. Carlos Ballesteros de Andrés
//  problem31
//
//  Este problema es una versión del de devolver el cambio
//  y se resuelve muy parecido
//
//

#include <iostream>
#include <set>
#include "Matriz.h"

using namespace std;

const int INF = 1e9;


//Coste: Θ(nC) tanto en tiempo como en espacio adicional

int codigoSecreto(set<int> &simbolos, string &mensaje){
    vector<int> solucion(mensaje.size(), 0);
    int aux = 0, num = 0;
    bool sirve = false;
    
    //Caso Base
    if (simbolos.find(mensaje[mensaje.size()-1]-48) != simbolos.cend()){
        solucion[mensaje.size()-1] = 1;}
    
    

    for (int i = mensaje.size()-2; i >= 0; i--){
        sirve = false;
        aux = 0;
        //Compruebo con la cifra actual
        if (simbolos.find(mensaje[i]-48) != simbolos.cend()){
            aux ++;
            sirve = true;
        }
        
        
        if (i + 1 < mensaje.size()){
            if (mensaje[i]-48 == 0 && mensaje[i+1]-48 == 0 )
                sirve = true;
            else{
                num = 0;
                //cojo las cifras para construir un número.
                for (int j = 0; j < 2; j++){
                    num = 10*num + (mensaje[i+j]-48);
                }
                //Compruebo que el número obtenido forme parte de los símboos disponibles
                if (simbolos.find(num) != simbolos.cend()){
                    aux ++;
                    sirve = true;
                }
            }
        }
        
        //Sise puede, compruebo con la actual más las dos siguientes
        if (i + 2 < mensaje.size()){
            if (mensaje[i]-48 == 0 && mensaje[i+1]-48 == 0 && mensaje[i+2]-48 == 0)
                sirve = true;
            else{
                num = 0;
                //cojo las cifras para construir un número.
                for (int j = 0; j < 3; j++){
                    num = 10*num + (mensaje[i+j]-48);
                }
                //Compruebo que el número obtenido forme parte de los símboos disponibles
                if (simbolos.find(num) != simbolos.cend()){
                    aux ++;
                    sirve = true;
                }
            }
        }
        else
            sirve = true;
        
        if (sirve && solucion[i+1]!= -1){
            if (aux > 0)
                solucion[i] = solucion[i+1] + aux -1;
            else
                solucion[i] = solucion[i+1];
        }
        else
            solucion[i] = -1;
    }
    
    return solucion[0];
}

bool resuelveCaso() {
    int N = 0, aux = 0, solucion = 0;
    string mensaje;
    //LEER DATOS DE ENTRADA
    cin >> N;
    
    if (N==0) // fin de la entrada
        return false;
    
    
    set<int> simbolos;
    
    for (int i = 0; i < N; i++){
        cin >>aux;
        simbolos.insert(aux);
    }
    
    cin >> mensaje;
    
    //resolver
    solucion = codigoSecreto(simbolos, mensaje);
    
    
    //escribir solucion
    if (solucion > 0)
        cout << solucion << endl;
    else
        cout << 0 << endl;
    
    return true;
}


int main() {
    while (resuelveCaso());
    return 0;
}