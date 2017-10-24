// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema mediante el uso de 2 funciones.
La primera es para crear el mapa del mar según las manchas de mediante un array de booleanos y a la vez crear 
el grafo con las uniones de las manchas contiguas en las 8  direcciones. A la vez que vamos creando los grupos
de las manchas de petróleo llevamos un máximo con el grupo más grande encontrado.
La segunda es para editar ese grafo y el array de booleanos cuando añadimos una nueva mancha el mar mediante
una nueva foto. Además de actualizar los grupos que había creados con la inclusión de una nueva mancha tenemos
que evaluar si los nuevos grupos superan en tamaño al máximo que llevamos acumulado, si es así lo actualizamos.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "ConjDisj.h"

using namespace std;

/*
En esta función vamos a ir leyendo el mapa de la cuadrícula del mar para así crear el array de booleanos que nos
marcará las posiciones en el mar donde tenemos petróleo. Gracias a ese array podremos establecer el grafo de 
conjuntos disjuntos que nos marcará los grupos creados mediante la consulta de los cuadrantes adyacentes en 4
direcciones en busca del contenido de petróleo. Lo hacemos solo en 4 direcciones (izquierda, esquina de arriba a 
la izquierda, arriba y esquina de arriba a la derecha) porque al estar formando ahora el grafo y el mapa de 
booleanos solo podemos comparar con lo anterior, es decir, solo con esas 4 posiciones, con las otras 4 no porque 
aún no las hemos leido.
A la vez que vamos haciendo esto, por cada mancha de petróleo llevamos guardado cual es la mayor mancha encontrada.

Coste: es del orden de O(F*C) siendo F el número de filas de la cuadrícula y C el número de columnas. Esto de debe 
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
En esta función hacemos lo mismo que en la de manchaInicial solo que lo hacemos para una única mancha, que 
es la nueva añadida, solo que esta vez las comprobaciones con los adyacentes lo hacemos en las 8 direcciones
puesto que ahora sí que tenemos creado el mapa completo.
Además actualizamos el máximo si el grupo que se ha creado ahora con esta nueva mancha supera en tamaño al 
máximo llevado hasta el momento.

Coste: es del orden del O(1) debido a que las operaciones de comparación, búsqueda en arrays y las uniones
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
Coste: es del orden de O(M + F) siendo M el coste de la función manchasInicial y F el número de fotos tomadas
para modificarlo. Aunque nunca se va a superar el coste de la primera función puesto que como máximo se podrán
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
