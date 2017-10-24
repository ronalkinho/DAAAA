// Grupo TAIS04, Juan José Prieto y Fernando Miñambres

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"

// Función que resuelve el problema, para ello se introduce cada pareja de
// personas conocidas en el mismo conjunto y se van añadiendo las personas
// que conocen a alguien de ese conjunto.
//
// Finalmente se busca el conjunto con mas elementos, que será la solución.
//
// La complejidad de la funcion es de O(M + N) siendo N el numero de
// personas y M el numero de relaciones, dado que se realizan operaciones
// de orden constante M veces para unir las parejas y N veces para encontrar
// el conjunto mas grande.
int resuelve(std::vector<size_t> const& datos, int const& n, int const& M) {
	ConjuntosDisjuntos conjunto(n + 1);
	std::vector<size_t> sol(n + 1, 0);
	int conjuntoMax = 1, result = 1;

	// Para cada pareja de personas conocidas, las emparejamos en un conjunto.
	for (size_t i = 0; i < M * 2; i = i + 2) {
		int a = datos[i], b = datos[i + 1];
		if (conjunto.buscar(a) != conjunto.buscar(b)) { // Si no conocian a nadie
			conjunto.unir(a, b);                        // del conjunto.
		}
	}

	// Recorremos todos los conjuntos para ver cual es el mas grande.
	for (size_t i = 1; i <= n; i++) {
		conjuntoMax = conjunto.buscar(i);
		sol[conjuntoMax]++;
		if (sol[conjuntoMax] > result) {
			result = sol[conjuntoMax];
		}
	}

	// Devolvemos el conjunto mas grande.
	return result;
}

//Funcion que resuleve el problema
void resuelveCaso() {
	size_t n, M, a, b, result = 1;
	std::cin >> n >> M;
	std::vector<size_t> datos(M * 2);

	// Introducimos las parejas en un vector por pares, es decir,
	// la posicion 0 y la 1 sera la primera pareja, la 2 y la 3 la
	// segunda pareja, y asi sucesivamente.
	for (size_t i = 0; i < M * 2; i = i + 2) {
		std::cin >> datos[i] >> datos[i + 1];
	}

	std::cout << resuelve(datos, n, M) << std::endl;
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