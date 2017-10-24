// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema mediante la idea recursiva que sigue:

El grafo se forma mediante por una matriz de adyacencia guardando los datos de la 
siguiente forma:
G[i][j]		=>		si i=j							0
			=>		si hya arista entre i y j		coste 
			=>		si no hay arista entre i y j	infinito

relations^k (i, j) = coste mínimo para ir de i a j pudiendo utilizar como vértices 					intermedios aquellos entre 1 y k.
relations^k (i, j) = mín{relations^k−1 (i, j), relations^k−1 (i, k) + relations^k−1 (k, j)}

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include "IndexPQ.h"
#include "Matriz.h"

using namespace std;

const int INF = 1000000000;
const int MOD = 1000000007;

/*
Aplicando la idea recursiva resolvemos el problema mediante el uso de una matriz de NxN
siendo N el número de personas y guardamos en dicha matriz a distancia entre una persona
i y otra j, si es la misma es 0, si no es alcanzable infinito y si podemos llegar es el
número de personas por las que tendremos que pasar para que esa persona i esté conectada 
con la j.
Luego para obtener el m´ximo grado de separación recorremos la matriz en busca del mayor 
valor y en el caso de encontrar algún infinito signifiacará que el grafo está desconectada.

Coste en tiempo: es del O(N^3) siendo N el número de personas.
Coste en espacio: el espacio requerido es de N^2 elementos enteros para la matriz y de un
map de strings con enteros de con tantos elementos como personas haya en el grafo.

*/
void relations(int personas, int relaciones) {
	Matriz<int> red(personas + 1, personas + 1, INF);
	unordered_map<string, int> pers;
	string p1, p2;
	int num = 1, i, j, max=0;
	bool desc = false;
	if (personas == 1) {
		cout << 0 << endl;
	}
	else {
		for (int k = 0; k < relaciones; ++k) {
			cin >> p1 >> p2;
			if (pers.find(p1) == pers.cend()) {
				pers.insert(std::pair<string, int>(p1, num));
				num++;
				red[pers[p1]][pers[p1]] = 0;
			}
			if (pers.find(p2) == pers.cend()) {
				pers.insert(std::pair<string, int>(p2, num));
				num++;
				red[pers[p2]][pers[p2]] = 0;
			}
			red[pers[p1]][pers[p2]] = 1;
			red[pers[p2]][pers[p1]] = 1;
		}

		for (int k = 1; k <= personas; ++k)
			for (int i = 1; i <= personas; ++i)
				for (int j = 1; j <= personas; ++j) {
					int temp = red[i][k] + red[k][j];
					if (temp < red[i][j]) { // es mejor pasar por k
						red[i][j] = temp;
						red[j][i] = temp;
					}
				}
		i = 1;
		while (i <= personas && !desc) {
			j = 1;
			while (j <= personas && !desc) {
				if (red[i][j] == INF)
					desc = true;
				else if (red[i][j] > max)
					max = red[i][j];
				++j;
			}
			++i;
		}

		if (desc)
			cout << "DESCONECTADA" << endl;
		else
			cout << max << endl;
	}
}

bool resuelveCaso() {
	int personas, relaciones;

	cin >> personas >> relaciones;

	if (!cin)
		return false;

	relations(personas, relaciones);

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