// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema gracias a un vector con tantas posiciones como caracteres tenga el mensaje en el cual
guardamos en cada posición el número de interpretaciones posibles hasta el momento del mensaje en cuestión.
El mecanismo de recursión en el que nos basamos trata de averiguar cuantas interpretaciones posibles hay desde
una posición i hasta el final de la cadena, empezando por el final y hasta llegar al principio.
Para ello siempre que se pueda (por la posición del i) comprobamos las posciones posteriores en las cuales
tomamos solo un digito, 2 digitos y 3 digitos como un simbolo y sumamos las interpretaciones en esos casos.

La idea recursiva que empleamos es a siguiente:

maneras(i) = número de interpretaciones del mensaje desde la posición i hasta el final del mensaje

maneras(i) = maneras(i+1) + maneras(i+2) + maneras(i+3) //Siempre y cuando la posición i del vector permita 
														//acceder a las posiciones i+1, i+2 e i+3, sino será
														//0 la que no se pueda ser accedida.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <string>
#include "IndexPQ.h"
#include "Matriz.h"

using namespace std;

const int INF = 1000000000;
const int MOD = 1000000007;

/*
Para resolver el problema pasando la solución recursiva a una de programación dinámicalo que hacemos es emplear
un vector para guardar todas las interpretaciones posibles desde el final de la cadena hasta la posición actual.
Empezaremos por el final en la cual se guarda un 1, puesto que se empieza con una única interpretación posible, y
seguiremos avanzando hasta el principio del mensaje, esta forma de recorrer el mensaje se debe a que para una
posición se necesita de las posiciones siguientes por lo que tenemos que calcularlas previamente.
Para cada posición se comprueba que haya posibilidad de coger los posteriores y se mira si ese simbolo (de 1, 2 o
3 cifras) es uno de los símbolos posibles, de ser así se contará la posición de ese elemento para sumarlo y
guardarlo en la i actual.
En el caso de que el digito de la posición i sea un 0 (espacio) entonces en la posición i actual se guardará en de
la posición i+1.
Con esto tenemos que la posición 0 del vector se guarda el número de interpretaciones posibles de todo el mensaje.

Coste en tiempo: es de O(N * log S) siendo N el número de caracteres del mensaje y S el número de símbolos del
lenguaje
Coste en espacio: el espacio requerido es de N elementos enteros, es decir, 4*N bytes, siendo N el número
de caracteres del mensaje
*/
void maneras(int simbolos) {
	int c, i, c1, c2, c3, lon, d1, d2, d3;
	set<int> codigos;
	string msg;

	for (int j = 1; j <= simbolos; j++) {
		cin >> c;
		codigos.insert(c);
	}
	cin >> msg;

	lon = i = msg.size();
	i = lon - 1;
	vector<int> formas(lon + 1, 0);
	formas[lon] = 1;

	while (i >= 0) {
		c1 = c2 = c3 = 0;
		d1 = msg[i] - '0';
		if (d1 != 0) {
			if (i + 1 <= lon) {
				if (codigos.find(d1) != codigos.end()) {//el conjunto contiene el codigo de un digito
					c1 = formas[i + 1];
				}
				if (i + 2 <= lon) {
					d2 = msg[i + 1] - '0';
					if (codigos.find(d1 * 10 + d2) != codigos.end()) {//el conjunto contiene el codigo de 2 digitos
						c2 = formas[i + 2];
					}
					if (i + 3 <= lon) {
						d3 = msg[i + 2] - '0';
						if (codigos.find(d1 * 100 + d2 * 10 + d3) != codigos.end()) {//el conjunto contiene el codigo de 3 digitos
							c3 = formas[i + 3];
						}
					}
				}
			}
		}
		else
			c1 = formas[i + 1];
		formas[i] = ((c1 + c2) % MOD + c3) % MOD;
		--i;
	}

	cout << formas[0] << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int simbolos;
	cin >> simbolos;
	while (simbolos != 0) {
		maneras(simbolos);
		cin >> simbolos;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}