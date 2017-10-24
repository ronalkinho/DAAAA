

// Grupo DA17, CARLOS BALLESTEROS DE ANDRÉS

// Para resolver este problema he necesitado una función recursiva que construye el árbol binario a partir de la entrada,
// así como otra función, también recursiva que devuelve la altura de un árbol a partir de la definición de la misma, esto es
// el máximo entre las alturas del hijo derecho e izquierdo, esta función es la misma que la del problema problem00 a la que se
//


#include <iostream>
#include <stdio.h>
#include "BinTree.h"
using namespace std;


BinTree<char> leerArbol (); // Función que lee la entrada y construlle el árbol binario
int profundidad( BinTree<char> arbol, bool &equilibrado); // Función recursiva que devuelve la altura de un árbol binario y si está equilibrado
void resuelveCaso(); //Resuelve un caso de prueba, leyendo la entrada y escribiendo la respuesta;


// El coste de la solución es lineal respecto el número de nodos del árbol,
// puesto que tiene que recorrer todos los nodos desde la raíz.

int profundidad( BinTree<char> arbol, bool &equilibrado) {
    int iz, dr;
    if(arbol.empty()) //Es hoja
        return 0;
    else{
        if (equilibrado){ // si no está equilibrado no sigo probando
            iz = (profundidad(arbol.left(), equilibrado);
            dr = profundidad(arbol.right(), equilibrado);
            if (iz - dr > 1) || (dr - profundidad(arbol.left(), equilibrado) > 1))
                equilibrado = false;
        }
    }
    
    return max(profundidad(arbol.left(), equilibrado), profundidad(arbol.right(), equilibrado)) +1;
}



void resuelveCaso() {
    bool sol = true;
    BinTree<char> arbol = leerArbol();
    
    profundidad(arbol, sol);
    
    if (sol)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
}


int main() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    return 0;
}


BinTree<char> leerArbol (){
    char raiz;
    cin >> raiz;
    
    if (raiz == '.')
        return BinTree <char>(); //si recibimos un punto devovlemos un árbol vacío.
    
    BinTree<char> hijoIz = leerArbol();  //llamada recursiva que construye el hijo izquierdo
    BinTree<char> hijoDr = leerArbol();  //llamada recursiva que construye el hijo derecho
    
    return BinTree<char>(hijoIz, raiz, hijoDr); // Se devuelve el árbol generado.
}