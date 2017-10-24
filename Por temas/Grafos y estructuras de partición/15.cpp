// Grupo TAIS04, Juan José Prieto y Fernando Miñambres

#include <iostream>
#include <string>
#include <sstream>
#include "GrafoDirigido.h"
#include "ManchasDePetroleo.h"

// Funcion que resuelve el problema con la ayuda de la clase "ManchasDePetroleo.h", que calcula el número
// de elementos de la zona contaminada mas grande y permite insertar nuevas zonas actualizando el valor 
// de la mas grande.
//
// La complejidad de la funcion es de O(N + M), siendo N el numero de celdas (filas * columnas) y M el
// numero de nuevas manchas introducidas, ya que se realizan operaciones de orden constante N veces para
// ver el numero de manchas iniciales y M veces para ver las nuevas manchas.
//
bool resuelveCaso() {
	int filas, col;
	std::string line;

	// Leemos las filas y las columnas de la rejilla.
	std::getline(std::cin, line);
	std::stringstream stream;
	stream << line;
	stream >> filas >> col;
	if (!stream) {
		return false;
	}

	// Leemos los datos de la rejilla.
	std::vector<std::vector<int>> matriz(filas, std::vector<int>(col));
	for (int i = 0; i < filas; i++) {
		std::getline(std::cin, line);
		for (int j = 0; j < col; j++) {
			char c = line.at(j);
			if (c == ' ') matriz[i][j] = 0;
			else if (c == '#')
				matriz[i][j] = 1;
		}
	}

	// Resolvemos el problema con la ayuda de la clase 
	ManchasDePetroleo manchas(matriz, filas, col);
	std::cout << manchas.getMax();

	int nuevasManchas;
	std::stringstream stream2;
	std::getline(std::cin, line);
	stream2 << line;
	stream2 >> nuevasManchas;
	for (int i = 0; i < nuevasManchas; i++) {
		int fila, columna;
		std::stringstream stream3;
		std::getline(std::cin, line);
		stream3 << line;
		stream3 >> fila >> columna;
		manchas.insertaMancha(matriz, fila, columna);
		std::cout << " " << manchas.getMax();
	}
	std::cout << std::endl;

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {

	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}