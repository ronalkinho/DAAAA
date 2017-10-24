// Grupo TAIS04, Juan José Prieto y Fernando Miñambres
#include <iostream>
#include <fstream>
#include "GrafoDirigido.h"
using namespace std;

// Función que resuelve el problema, para ello se hace un recorrido BFS utilizando
// como siguente nodo a visitar el numero actual por cada una de las operaciones
// disponibles. Se utilizan dos vectores, uno para ver si ya se ha visitado el 
// siguiente numero y otro para ver la distancia (numero de operaciones) hasta 
// ese numero.
//
// La complejidad del problema es de O(n), siendo n el numero de nodos/numeros que
// se visitan, ya que para cada uno de ellos hace operaciones de O(1).
int resolver(int const& origen, int const& destino) {
	bool encontrado = false;
	std::vector<bool> marked(10001);     // marked[v] = hay camino s-v?
	std::vector<size_t> distTo(10001);   // distTo[v] = número de aristas en el camino s-v más corto

	std::queue<size_t> q;
	
	// Inicializamos el origen
	distTo[origen] = 0;
	marked[origen] = true;
	q.push(origen);

	// Recorrido bfs
	while (!q.empty() && !encontrado) {
		size_t v = q.front(); q.pop();
		int w = (v + 1) % 10000; // Botón +1
		if (!marked[w]) {
				distTo[w] = distTo[v] + 1;
				marked[w] = true;
				q.push(w);
		}
		if (w == destino)encontrado = true;

		w = (v * 2) % 10000; // Botón * 2
		if (!marked[w]) {
			distTo[w] = distTo[v] + 1;
			marked[w] = true;
			q.push(w);
		}
		if (w == destino)encontrado = true;

		w = v / 3; // Botón / 3
		if (!marked[w]) {
			distTo[w] = distTo[v] + 1;
			marked[w] = true;
			q.push(w);
		}
		if (w == destino)encontrado = true;
	}

	// Devolvemos el camino minimo del origen hasta el destino.
	return distTo[destino];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int origen, destino;

	cin >> origen >> destino;

	if (!cin) // fin de la entrada
			return false;

	cout << resolver(origen, destino) << endl;
	
	return true;
}
int main() {
	// ajustes para que cin extraiga directamente de un fichero
	#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	while (resuelveCaso());

	// para dejar todo como estaba al principio
	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif

	return 0;
}