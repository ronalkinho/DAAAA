// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

/*
Resolvemos el problema mediante el uso de 2 funciones.
La primera es para crear el mapa del mar seg�n las manchas de mediante un array de booleanos y a la vez crear 
el grafo con las uniones de las manchas contiguas en las 8  direcciones. A la vez que vamos creando los grupos
de las manchas de petr�leo llevamos un m�ximo con el grupo m�s grande encontrado.
La segunda es para editar ese grafo y el array de booleanos cuando a�adimos una nueva mancha el mar mediante
una nueva foto. Adem�s de actualizar los grupos que hab�a creados con la inclusi�n de una nueva mancha tenemos
que evaluar si los nuevos grupos superan en tama�o al m�ximo que llevamos acumulado, si es as� lo actualizamos.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "ConjDisj.h"

using namespace std;

/*
En esta funci�n vamos a ir leyendo el mapa de la cuadr�cula del mar para as� crear el array de booleanos que nos
marcar� las posiciones en el mar donde tenemos petr�leo. Gracias a ese array podremos establecer el grafo de 
conjuntos disjuntos que nos marcar� los grupos creados mediante la consulta de los cuadrantes adyacentes en 4
direcciones en busca del contenido de petr�leo. Lo hacemos solo en 4 direcciones (izquierda, esquina de arriba a 
la izquierda, arriba y esquina de arriba a la derecha) porque al estar formando ahora el grafo y el mapa de 
booleanos solo podemos comparar con lo anterior, es decir, solo con esas 4 posiciones, con las otras 4 no porque 
a�n no las hemos leido.
A la vez que vamos haciendo esto, por cada mancha de petr�leo llevamos guardado cual es la mayor mancha encontrada.

Coste: es del orden de O(F*C) siendo F el n�mero de filas de la cuadr�cula y C el n�mero de columnas. Esto de debe 
a que la operaciones que se ejecutan en el bucle son constantes. 
*/
int manchasInicial(ConjDisj &mar, bool *petroleo, int f, int c){
	int act = 0, max = 0, z;
	char celda;

	for (int i = 0; i < f; ++i){
		for (int j = 1; j <= c; ++j){
			z = j + i*c;
			cin.get(celda);
			if (celda == '\n')
				cin.get(celda);
			if (celda == '#'){
				petroleo[z] = true;
				if (j > 1){//Izquierda
					if (petroleo[z-1])
						mar.unir(z, z-1);
					if (i > 0){//Esquina sup izq
						if (petroleo[z-1-c])
							mar.unir(z, z-1-c);
					}
				}
				if (i > 0){//Arriba
					if (petroleo[z-c])
						mar.unir(z, z-c);
					if (j < c){//Esquina sup der
						if (petroleo[z+1-c])
							mar.unir(z, z+1-c);
					}
				}
				act = mar.size(z);
				if (act > max)
					max = act;
			}else
				petroleo[z] = false;
		}
	}

	cout << max << " ";
	
	return  max;
}

/*
En esta funci�n hacemos lo mismo que en la de manchaInicial solo que lo hacemos para una �nica mancha, que 
es la nueva a�adida, solo que esta vez las comprobaciones con los adyacentes lo hacemos en las 8 direcciones
puesto que ahora s� que tenemos creado el mapa completo.
Adem�s actualizamos el m�ximo si el grupo que se ha creado ahora con esta nueva mancha supera en tama�o al 
m�ximo llevado hasta el momento.

Coste: es del orden del O(1) debido a que las operaciones de comparaci�n, b�squeda en arrays y las uniones
en los conjuntos disjuntos tienen un coste constante
*/
int nuevaFoto(ConjDisj &mar, bool *petroleo, int f, int c, int i, int j, int mx){
	int max = mx, act = 0, z = j + i*c;
	petroleo[z] = true;

	if (j > 1){
		if (petroleo[z-1])//Izq
			mar.unir(z, z-1);
		if (i > 0){
			if (petroleo[z-1-c])//Esq izq arriba
				mar.unir(z, z-1-c);
		}
	}
	if (i > 0){
		if (petroleo[z-c])//Arriba
			mar.unir(z, z-c);
		if (j < c){
			if (petroleo[z+1-c])//Esq der arriba
				mar.unir(z, z+1-c);
		}
	}
	if (j < c){
		if (petroleo[z+1])//Der
			mar.unir(z, z+1);
		if (i < f-1)
			if (petroleo[z+1+c])//Esq der abajo
				mar.unir(z, z+1+c);
	}
	if (i < f-1){
		if (petroleo[z+c])//Abajo
			mar.unir(z, z+c);
		if (j > 1)
			if (petroleo[z-1+c])//Esq if izq
				mar.unir(z, z-1+c);
	}

	act = mar.size(z);
	if (act > max)
		max = act;

	cout << max << " ";

	return  max;
}


/*
Coste: es del orden de O(M + F) siendo M el coste de la funci�n manchasInicial y F el n�mero de fotos tomadas
para modificarlo. Aunque nunca se va a superar el coste de la primera funci�n puesto que como m�ximo se podr�n
echar tantas fotos como filas*columnas haya en la matriz, por lo que el coste es de O(M)
*/
bool resuelveCaso() {
	int filas, columnas, fotos, f, c;

	cin >> filas >> columnas;

	if (!cin)
		return false;

	ConjDisj mar(filas*columnas + 1);
	bool *petroleo;
	int max;
	petroleo = (bool*)malloc(sizeof(bool)*filas*columnas+1);

	max = manchasInicial(mar, petroleo, filas, columnas);

	cin >> fotos;
	for (int i = 0; i < fotos; i++){
		cin >> f >> c;
		max = nuevaFoto(mar, petroleo, filas, columnas, f-1, c, max);
	}
	cout << endl;

	free(petroleo);

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
