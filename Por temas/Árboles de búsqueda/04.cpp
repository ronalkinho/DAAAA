// TAIS04 - Fernando Miñambres y Juan José Prieto

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "TreeMap_AVL.h"

using namespace std;

// Función que resuelve el problema insertando en un vector los capitulos emitidos y
// recoriendolo para introducirlos en un TreeMap.
// 
// Al introducirlos, si estos no existian (el valor asociado al operador[] es 0), 
// se introducen en el arbol junto con su posicion actual y se comprueba si es el maximo
// periodo transcurrido entre el dia actual y la ultima repeticion conocida. 
// Si ya existia, se calculan los dias transcurridos entre la ultima repeticion de ese
// elemento y el dia actual.
//
// Finalmente se comprueba si es el maximo periodo buscado. 
//
// El coste de la función es de O(N log N), siendo N el número de capitulos emitidos, ya
// que recorrerá todos ellos y para uno hace operaciones con complejidad O(log N) 
// (operaciones insert y []).
//
int maximoDias(vector<int> const& datos) {
	TreeMap<int, int> arbol;
	bool repetido = false;
	int maxPeriodo = 0, inicioPeriodo = 0;

	//Recorremos el vector instrocudiendo los capitulos en un TreeMap.
	for (int i = 1; i < datos.size(); i++) {
		int ultimaRepeticion = arbol[datos[i]];
		int periodo;
		if (ultimaRepeticion != 0) {
			arbol.insert(datos[i], i);

			inicioPeriodo = max(ultimaRepeticion, inicioPeriodo);
			periodo = i - inicioPeriodo;
		}
		else {
			arbol.insert(datos[i], i);
			periodo = i - inicioPeriodo;
		}

		if (periodo > maxPeriodo) {
			maxPeriodo = periodo;
		}
	}

	// Devolvemos el maximo de días sin capitulos repetidos.
	return maxPeriodo;
}

// Lee los datos de un caso de prueba.
vector<int> leerDatos() {
	// Introducimos el número de capítulos que Andrés apunta.
	int numCapitulos;
	std::cin >> numCapitulos;

	// Creamos un vector y lo rellenamos con los capítulos emitidos.
	vector<int> vector(numCapitulos + 1); // Para empezar en el dia 1.
	for (int i = 1; i <= numCapitulos; i++) {
		std::cin >> vector[i];
	}

	// Devolvemos el vector.
	return vector;
}

// Resuelve un caso de prueba.
void resuelveCaso() {
	// Leemos los datos.
	auto datos = leerDatos();

	// Llamamos a la función que calcula el máximo de días en los que no se repite ningún capítulo
	// y mostramos el resultado.
	cout << maximoDias(datos) << endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}