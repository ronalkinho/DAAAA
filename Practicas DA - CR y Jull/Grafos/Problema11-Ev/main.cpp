// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema añadiendo las conexiones entre los diferentes vértices según los vamos leyendo y por cada
unión vemos el tamaño del grupo de uno de los elementos que acabamos de unir y en el caso de que se mayor que el
máximo encontrado hasta el momento se le sustituye por este nuevo. Si no hay relaciones entonces el grupo mínimo 
es de 1 persona
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "ConjDisj.h"

using namespace std;

/*
Coste: es lineal en el número de relaciones que hay entre los vertices debido a que las búsquedas y  las uniones
son constantes, por tanto el algoritmo es O(N) donde N es el número de pares de amigos
*/
void resuelveCaso() {
	int pers, rel, p1, p2, max=1, act=0;
	cin >> pers >> rel;
	ConjDisj a(pers+1);
	for (int i = 0; i < rel; ++i){
		cin >> p1 >> p2;
		a.unir(p1, p2);
		act = a.size(p1);
		if (act > max)
			max = act;
	}
	cout << max << endl;
}

int main() {
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int num;
	std::cin >> num;
	for (int i = 0; i < num; ++i){
		resuelveCaso();
	}
	
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}
