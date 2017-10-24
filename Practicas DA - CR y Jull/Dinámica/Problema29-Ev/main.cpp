// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema mediante programación dinámica.
Para ello utilizamos una serie de elementos:
- Un vector que guarda las puntos de los sectores que componen la diana
- Una matriz que va a almacenar el número de veces que tiramos a cada sector para obtener la puntuación deseada,
siendo las filas los sectores ordenados de menor a mayor y en las columnas la puntuación unidad a unidad hasta
el valor objetivo.

La idea recursiva que hemos seguido para sacar el problema es la siguiente:

tiradas(i,j) = número mínimo de tiradas para llegar a la puntuación j considerando los sectores de la diana
				del 1 al i.

tiradas(i,j)	=>		si puntos[i] > j		tiradas(i-1,j)
						si puntos[i] <= j		min{tiradas(i-1,j), tiradas(i,j-1)}

Como casos base tenemos que:
tiradas(i,0) = 0;
tiradas(0,j) = infinito

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "IndexPQ.h"
#include "Matriz.h"

using namespace std;

const int INF = 1e9;

/*
La función va a realizar una búsqueda gracias a la matríz, de todas las posibilidades tirando o no a los sectores y
cuantas veces, sería algo muy parecido a la búsqueda en árboles binarios en el que un hijo sería tirar a dicho sector
y el otro no tirar a el.

Empezamos a recorrer la matriz de arriba a abajo y de izquierda a derecha, vamos rellenandola.
Para cada valor de sector y para cada puntuación tenemos que comprobar que el valor del sector para las tiradas
actuales no sobrepasa el de la puntuación actual puesto que esta se va incrementando hasta alcanzar la puntuación
objetivo.
Si es mayor no podemos tirar a ese sector por lo que en esa posición de la matriz (valor del sector y puntuación
actual) guardamos el número de tiradas que llevamos para ese mismo valor de puntuación actual pero sin haber tirado
a ese sector, es decir, el de la posición de la misma puntuación pero el sector anterior.
Pero si podemos tirar a el entonces guardaremos el valor mínimo de tiradas entre no tirar a este sector para ese valor
de puntuación actual y el tirar a ese sector.

Para saber a que sectores hemos tirado y en orden de mayor a menor, lo que hacemos es situarnos en la posición de la matriz
para el ultimo sector y el valor de la puntuación objetivo. Entonces empezamos a recorrerla sector a sector de una determinada
forma.
Si el valor  de ese sector cabe en lo que nos queda de puntuación (puesto que vamos decrementandola hasta llegar a 0)
entonces comprobamos si el valor de la posición actual es el mismo + 1 que el que hay en esa misma fila pero tantas posiciones
antes como valor tenga el sector, si es así es que hemos tirado en ese sector, así que lo mostramos y decrementamos la puntuación
que nos queda por alcanzar y en la siguiente vuelta del bucle comprobaremos el mismo sector por si hemos tirado más veces. Al
comprobar esto primero le damos prioridad a los sectores de mayor valor por lo que son los que tomamos como solución.
Si esto no se cumple comprobamos que al igual que antes el valor del sector cabe en lo que nos queda de puntuación y si es así
miramos si el número de tiradas es distinto al de la misma puntuación pero con el sector anterior. Si esto se cumple es que
tenemos que hacer una sola tirada a este sector. La condición actual nos dice que podemos elegir entre coger de este sector y la
anterior a que si podemos coger más de este sector, por tanto, con anterior falsa tenemos que solo tiramos una vez aquí, así que
mostramos el valor, restamos la puntuación y pasamos al siguiente sector.

Coste en tiempo: es del O(N*M) siendo N el número de sectores que hay y M el número de puntos que hay que alcanzar
Coste en espacio: el espacio requerido es de N*M números enteros, es decir, 4*N*M bytes, siendo N el número de sectores que hay
y M el número de puntos que hay que alcanzar, en definitiva, una matriz de elementos de ese tamaño
*/
void tiradas(int valor, int sectores) {
	int total, p;
	vector<int> puntos(sectores + 1);

	for (int i = 1; i <= sectores; i++) {
		cin >> p;
		puntos[i] = p;
	}

	Matriz<int> dianas(sectores + 1, valor + 1, INF);
	//Rellenar la matriz
	for (int i = 1; i <= sectores; ++i) {
		dianas[i][0] = 0;
		for (int j = 1; j <= valor; ++j) {
			if (puntos[i] > j)
				dianas[i][j] = dianas[i - 1][j];
			else {
				dianas[i][j] = min(dianas[i - 1][j], dianas[i][j - puntos[i]] + 1);
			}
		}
	}
	total = dianas[sectores][valor];
	if (total > valor)
		cout << "Imposible";
	else {
		cout << total << ":";


		int i = sectores;
		int resto = valor;
		while (i >= 1) {
			if (puntos[i] <= resto && dianas[i][resto] == (dianas[i][resto - puntos[i]]) + 1) {
				// tomamos una moneda de tipo i
				cout << " " << puntos[i];
				resto = resto - puntos[i];
			}
			else {
				if (puntos[i] <= resto && dianas[i][resto] != dianas[i - 1][resto]) {
					cout << " " << puntos[i];
					resto = resto - puntos[i];
				}
				--i;
			}

		}
	}

	cout << endl;
}

bool resuelveCaso() {
	int valor, sectores;

	cin >> valor >> sectores;

	if (!cin)
		return false;

	tiradas(valor, sectores);

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}