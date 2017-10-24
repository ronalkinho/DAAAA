//
//  Grupo DA17. Carlos Ballesteros de Andrés
//
//  Soluciono este problema utilizando una cola de priridad de máximos,
//  de esta forma podemos ir sacando siempre los libros de mayor precio
//  para obtener el mayor descuento.



#include <iostream>
#include "PriorityQueue.h"

using namespace std;


// El coste de las operaciones en una cola de prioridad es Log (N),
// Por lo que el coste de la soliución es es NLog(N), siendo N el número
// de libros que queremos comprar.


bool resuelvecaso(){
    int num, libro, ahorro;
    cin >> num;
    PriorityQueue<int, greater<int>> libros;
    for (int i = 0; i < num; i++){
        cin >> libro;
        libros.push(libro);
    }
    
    if(!cin)
        return false;
    
    ahorro = 0;
    while (!libros.empty()){
        if(!libros.empty())
            libros.pop();
        
        if(!libros.empty())
            libros.pop();
        
        if(!libros.empty()){
            ahorro += libros.top();
            libros.pop();
        }
    
    }
    
    cout << ahorro << endl;
    
    return true;
}

int main(int argc, const char * argv[]) {
 
    while (resuelvecaso());
    return 0;
}


