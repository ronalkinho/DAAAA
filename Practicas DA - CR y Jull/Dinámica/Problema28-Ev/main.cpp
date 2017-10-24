// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema mediante programación dinámica.
Para ello utilizamos una serie de elementos:
- Un vector que guarda las profundidades a las cuales se encuentran los tesoros, dicha profundidad será
3*p porque si está a profundidad de p, tardaremos 1p en bajar a por el y 2p en subirlo, por tanto
3p de tiempo consumido de la botella.
- Un vector que guarda la cantidad de oro de cada tesoro
- Una matriz que va a almacenar para cada tesoro y capacidad de la botella un valor, siendo es valor 0
si no hemos accedido o el valor del botín obtenido, pudiendo ser el que se obtiene al ir a buscar
ese tesoro o el que se obtinene si tomamos la decisión de no cogerlo.
- Un vector de booleanos que nos marcará a true aquellos cofres que hemos recatado para así mostrarlos.

La idea recursiva que hemos seguido es la que sigue:

buscaOro(i,j) = máximo valor de los cofres que puedo recoger con una cantidad de oxígeno j en la botella
				considerando los cofres del 1 al i

buscaOro(i,j) =		si profundidad[i] > j		buscaOro(i-1,j)
					si profundidad[i] <= j		max{buscaOro(i-1,j), mochila(i-1, j-profundidad[i]) + oro[i]}

Como casos base tenemos:
buscaOro(0,j) = 0		con 0 <= j <= capacidadBotella
buscaOro(i,0) = 0		con 0 <= i <= numeroCofres

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "IndexPQ.h"
#include "Matriz.h"

using namespace std;

/*
La función va a realizar una búsqueda gracias a la matríz, de todas las posibilidades cogiendo o no los tesoros,
sería algo muy parecido a la búsqueda en árboles binarios en el que un hijo sería coger dicho cofre y el otro no
cogerlo.

Empezamos a recorrer la matriz de arriba a abajo y de izquierda a derecha.
Para cara posición de un cofre y un valor del oxígeno de la botella consumido tenemos que comprobar que la
profundidad a la que se encuentra ese cofre es menor que la cantidad de oxígeno que nos queda en la botella. Si es
mayor entonces no podemos ir a por ese cofre, por lo que en su posición de la matriz guardamos el valor de oro que
teníamos para esa misma capacidad de la botella pero del objeto anterior. Pero si podemos cogerlo entonces lo que
guardaremos será el máximo valor de oro obtenido entre la decisión de coger el cofre y de no cogerlo.

Para saber que cofres hemos cogido solo tenemos que recorrer la matriz de arriba a abajo por los cofres y empezando
con la botella llena, si el valor de un cofre para la posición actual de oxígeno es igual a la del objeto anterior
significa que no lo cogimos, por lo que no lo marcamos en el vector de booleanos, de lo contrario lo marcamos y
restamos el tiempo empleado para llegar hasta él a la capacidad de la botella actual.

Coste en tiempo: es del O(N*M) siendo N el número de cofres totales que hay y M el número de segundos que tiene la
botella de capacidad
Coste en espacio: el espacio requerido es de N*M números enteros, es decir, 4*N*M bytes, siendo N el número de cofres
totales que hay y M el número de segundos que tiene la  botella de capacidad, en definitiva, una matriz de elementos
de ese tamaño.
*/
void buscaOro(int botella, int cofres) {
	int valor, p, o;
	vector<int> profundidad(cofres + 1);
	vector<int> oro(cofres + 1);

	for (int i = 1; i <= cofres; i++) {
		cin >> p >> o;
		profundidad[i] = 3 * p;
		oro[i] = o;
	}

	Matriz<int> tesoros(cofres + 1, botella + 1, 0);
	//Rellenar la matriz
	for (int i = 1; i <= cofres; ++i) {
		for (int j = 1; j <= botella; ++j) {
			if (profundidad[i] > j)
				tesoros[i][j] = tesoros[i - 1][j];
			else
				tesoros[i][j] = max(tesoros[i - 1][j], tesoros[i - 1][j - profundidad[i]] + oro[i]);
		}
	}
	valor = tesoros[cofres][botella];
	cout << valor << endl;

	//Cálculo de los cofres que nos llevamos
	int resto = botella, cont = 0;
	vector<bool> cogidos(cofres + 1);
	for (int i = cofres; i >= 1; --i) {
		if (tesoros[i][resto] == tesoros[i - 1][resto]) {
			//No cogemos el cofre i
			cogidos[i] = false;
		}
		else { //Sí cogemos el cofre i
			cogidos[i] = true;
			cont++;
			resto = resto - profundidad[i];
		}
	}
	cout << cont << endl;
	for (int i = 1; i <= cofres; i++)
		if (cogidos[i])
			cout << profundidad[i] / 3 << " " << oro[i] << endl;

	cout << "----" << endl;
}

bool resuelveCaso() {
	int botella, numCofres;

	cin >> botella >> numCofres;

	if (!cin)
		return false;

	buscaOro(botella, numCofres);

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