// TAIS04 - Fernando Miñambres y Juan José Prieto

#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <vector>
#include "PriorityQueue.h"

using namespace std;

// Funcion que calcula la mediana doble, para ello se utilizan dos
// colas de prioridad. En una de ellas se guardaran los datos con un
// valor mayor al valor de la mediana, ordenados de menor a mayor. En
// la otra se guardaran el resto de datos a la inversa.
//
// Cada vez que se introduce un valor, se calcula en que cola guardarlo
// en funcion del primero de cada una. Luego se balancea (si es necesario)
// y se calcula la mediana en funcion de si los datos son pares o
// impares.
//
// Finalmente se devuelve la mediana doble multiplicandola por dos.
//
// El coste de la funcion es de O(n log n), siendo n el numero de datos
// obtenidos, dado que se realizan operaciones de O(log n) para cada dato. 
int medianaDoble(int const& nuevoDato, PriorityQueue<int, greater<int>> &maximos, PriorityQueue<int, less<int>> &minimos) {
	double mediana = 0;

	// Guardamos el dato en la cola correspondiente.
	if (nuevoDato > minimos.top()) {
		minimos.push(nuevoDato);
	}
	else {
		maximos.push(nuevoDato);
	}

	// Balanceamos.
	if (signed(minimos.size() - maximos.size()) > 1) {
		maximos.push(minimos.top());
		minimos.pop();
	}
	else if (signed (maximos.size() - minimos.size()) > 1) {
		minimos.push(maximos.top());
		maximos.pop();
	}

	// Calculamos la mediana en funcion de si es par o impar.
	if (minimos.size() > maximos.size()) {
		mediana = minimos.top();
	}
	else if (maximos.size() > minimos.size()) {
		mediana = maximos.top();
	}
	else {
		mediana = double(maximos.top() + minimos.top()) / 2;
	}

	return mediana * 2;
}

// Lee los datos de un caso de prueba.
vector<int> leerDatos(int const &N) {
	// Creamos un vector y lo rellenamos con los datos recogidos.
	vector<int> vector(N); // Para empezar en el dia 1.
	for (int i = 0; i < N; i++) {
		std::cin >> vector[i];
	}

	// Devolvemos el vector.
	return vector;
}

// Resuelve un caso de prueba.
bool resuelveCaso() {
	// Leemos el numero de datos;
	int N;
	cin >> N;

	if (N == 0)
		return false;

	// Leemos los datos.
	auto datos = leerDatos(N);
	
	// Creamos las estructuras con las que manejaremos los datos.
	PriorityQueue<int, greater<int>> maximos;
	PriorityQueue<int, less<int>> minimos;

	// Para el primer dato, la mediana doble sera su valor por dos.
	// Lo guardamos en la cola que primero consultaremos.
	cout << datos[0] * 2;
	minimos.push(datos[0]);

	// Para el resto de datos llamamos a la función que calcula la 
	// mediana doble y mostramos el resultado.
	for (int i = 1; i < N; i++) {
		cout << " " << medianaDoble(datos[i], maximos, minimos);
	}
	cout << endl;

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
	system("pause");
#endif

	return 0;
}