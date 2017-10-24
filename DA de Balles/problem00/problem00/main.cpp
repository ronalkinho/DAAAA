

// Grupo DA17, CARLOS BALLESTEROS DE ANDRÉS

// Para resolver este problema he necesitado una función recursiva que construye el árbol binario a partir de la entrada,
// así como otra función, también recursiva que devuelve la altura de un árbol a partir de la definición de la misma, esto es
// el máximo entre las alturas del hijo derecho e izquierdo.


#include <iostream>
#include <stdio.h>
#include "BinTree.h"
using namespace std;


BinTree<char> leerArbol (); // Función que lee la entrada y construlle el árbol binario
int profundidad( BinTree<char> arbol); // Función recursiva que devuelve la altura de un árbol binario
void resuelveCaso(); //Resuelve un caso de prueba, leyendo la entrada y escribiendo la respuesta;


// El coste de la solución es lineal respecto el número de nodos del árbol,
// puesto que tiene que recorrer todos los nodos desde la raíz.

int profundidad( BinTree<char> arbol) {
    if(arbol.empty())
        return 0;
    else
        return max(profundidad(arbol.left()), profundidad(arbol.right())) +1;
}


void resuelveCaso() {
    BinTree<char> arbol = leerArbol();
    int sol = profundidad(arbol);
    cout << sol << endl;
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