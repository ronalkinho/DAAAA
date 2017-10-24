// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include<iostream>
#include<fstream>
#include"Matriz.h"
#include<string>
#include"TreeMap_AVL.h"
using namespace std;


/*maxGrado(i, j) = Siendo i un individuo conectado a otro individuo j
Matriz de adyacencia:
					maxGrado(i, j) = 0,   si i = j
					maxGrado(i, j) = 1,   si hay conexion entre i, j
					maxGrado(i, j) = Infinito,   si no hay conexion entre i, j

Definicion de la funcion:
						C^k(i, j) = coste mínimo para ir de i a j pudiendo utilizar vértices intermedios entre 1 y k.

Caso recursivo:
				C^k(i, j) = min(C^k-1(i, j), C^k-1(i, k) + C^k-1(k, j))

Caso base (cuando k = 0):
						C^0(i, j) = G(i, j),   si i != j
						C^0(i, j) = 0,   si i = j


Coste en espacio: O(N*N), donde N es el número de nodos del grafo
Coste en tiempo:  O(N*N*N), donde N es el número de nodos del grafo
*/
int maxGrado(Matriz<int> &G, Matriz<int> &camino) {

	int n = G.numfils() - 1;
	
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int temp = G[i][k] + G[k][j];
				if (temp < G[i][j]) {
					G[i][j] = temp;
				}
			}
		}
	}

	int sol = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (G[i][j] > sol){
				sol = G[i][j];
			}
		}
	}

	return sol;
}

bool resuelveCaso() {

	int v, a;
	int pos = 0;
	string p1 = "";
	string p2 = "";

	cin >> v >> a;

	if (!cin) return false;

	Matriz<int> G(v + 1, v + 1, 10001);

	TreeMap<string, int> t_personas;

	for (int i = 1; i <= v; i++) {
		G[i][i] = 0;
	}


	for (int i = 0; i < a; i++) { //Creo la matriz iniciar
		cin.ignore();
		cin >> p1;
		cin.ignore();
		cin >> p2;

		if (t_personas.contains(p1) && t_personas.contains(p2)) {
		}
		else if (!t_personas.contains(p1) && t_personas.contains(p2)) {
			pos++;
			t_personas.insert(p1, pos);			
		}
		else if (t_personas.contains(p1) && !t_personas.contains(p2)) {
			pos++;
			t_personas.insert(p2, pos);			
		}
		else {
			pos++;
			t_personas.insert(p1, pos);
			pos++;
			t_personas.insert(p2, pos);
		}
		G[t_personas[p1]][t_personas[p2]] = 1;
		G[t_personas[p2]][t_personas[p1]] = 1;
	}

	Matriz<int> camino(v + 1, v + 1, 0);

	int sol = maxGrado(G, camino);

	if (sol == 10001){
		cout << "DESCONECTADA" << endl;
	}
	else {
		cout << sol << endl;
	}

	return true;
}

int main() {

#ifndef DOMJUDGE

	ifstream in("casos.txt");
	auto cinbf = cin.rdbuf(in.rdbuf());

#endif


	while (resuelveCaso());


#ifndef DOMJUDGE

	cin.rdbuf(cinbf);
	system("pause");

#endif

	return 0;
}