

// Grupo DA17, CARLOS BALLESTEROS DE ANDRÉS

// Para resolver este problema he necesitado una función recursiva que construye el árbol binario a partir de la entrada,
// así como otra función, también recursiva que devuelve la altura de un árbol y si está equilibrada, que es la misma del
// problema 01. A esta se la suma la función AVL que recorre todo el árbol comprobando que para cada subarbol no haya ninguna
// clave mayor en el hijo izquierdo ni ninguna menor en el derecho.


#include <iostream>
#include <stdio.h>
#include "BinTree.h"
using namespace std;


BinTree<int> leerArbol (); // Función que lee la entrada y construlle el árbol binario
int profundidad( BinTree<int> arbol, bool &equilibrado); // Función recursiva que devuelve la altura de un árbol binario y si está equilibrado
int avl (BinTree<int> arbol, int &max, int &min, bool &correcto); //Función que recorre el árbol comprobando el valor de las claves
void resuelveCaso(); //Resuelve un caso de prueba, leyendo la entrada y escribiendo la respuesta;


// El coste de la solución es lineal respecto el número de nodos del árbol,
// puesto que tiene que recorrer todos los nodos desde la raíz dos veces,
// Una en la función profundidad y otra en la función avl O(f(2N)) siendo
// N el número de nodos.

int profundidad( BinTree<int> arbol, bool &equilibrado) {
    int iz = 0, dr = 0;
    if(arbol.empty()) //Es hoja
        return 0;
    else{
        if (equilibrado){ // si no está equilibrado no sigo probando
            iz = profundidad(arbol.left(), equilibrado);
            dr = profundidad(arbol.right(), equilibrado);
            if ((iz - dr > 1) || (dr - iz > 1))
                equilibrado = false;
        }
    }
    return max(iz, dr) +1;
}


int avl (BinTree<int> arbol, int &max, int &min, bool &correcto){
    int num = -1;
    if (arbol.left().empty() && arbol.right().empty()){ // si el nodo es hoja
        if (arbol.root() <= min)
            correcto = false;
        else
            min = arbol.root();
        
            max = arbol.root();
        
        return arbol.root();
    }
    
    else{
        num = arbol.root();
        //comprobamos el hijo izquierdo
        if (!arbol.left().empty()){
            avl (arbol.left(), max, min, correcto);
            if (num > min)
                min = num;
            else
                correcto = false;
        }
        //comprobamos el hijo derecho
        if (!arbol.right().empty()){
            avl (arbol.right(), max, min, correcto);
            if (num < max)
                max = num;
            else
                correcto = false;
        }
        return arbol.root();
    }
}

void resuelveCaso() {
    bool sol = true;
    int min = -2147483647, max = 2147483647; //Las macros INT_MIN y INT_MAX dan fallo en el Juez
    BinTree<int> arbol = leerArbol();
    
    profundidad(arbol, sol);
    //Si no está equilibrado o está vacío no seguimos mirando
    if (sol && !arbol.empty())
        avl(arbol, max, min, sol);
    
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


BinTree<int> leerArbol (){
    int raiz;
    cin >> raiz;
    
    if (raiz == -1)
        return BinTree <int>(); //si recibimos un -1 devovlemos un árbol vacío.
    
    BinTree<int> hijoIz = leerArbol();  //llamada recursiva que construye el hijo izquierdo
    BinTree<int> hijoDr = leerArbol();  //llamada recursiva que construye el hijo derecho
    
    return BinTree<int>(hijoIz, raiz, hijoDr); // Se devuelve el árbol generado.
}