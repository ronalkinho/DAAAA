//TAIS04 Fernando Miñambres y Juan José Prieto
//
//El problema se resuelve almacenando en un struct los datos de entrada(duracion y puntuacion de las canciones).
//Estos datos a su vez son almacenados en un vector de Canciones ordenado de mayor a menor beneficio por segundo, es decir,
//ordenados por (puntuacion/duracion).
//Una vez ordenados, como el problema es de maximizacion, tenemos que encontrar una cota superior de la mejor solución alcanzable,
// y lo conseguimos mediante la función calculo_voraz(). También vamos probando si podemos meter la canción en la cara 1, la cara 2 o
//si no podemos meterlo en ninguna cara.

//Por tanto, el problema consiste en Maximizar (sumatorio desde i=1 a n) de Xi*Pi, 
//con la restricción de (sumatorio desde i=1 a n) de Xi*Di <= duracion
//donde Xi puede tomar valor {0,1} para indicar si grabamos la canción o no, Pi indica la punuacion de la canción i,
//Di indica la duracion de la cancion i y duracion corresponde al tiempo de grabacion disponible de la cinta.

#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <climits>
#include "PriorityQueue.h"

using namespace std;

struct Cancion {
	float duracion;
	float puntuacion;
};

struct Nodo {
	vector<bool> solA;
	vector<bool> solB;
	int k;
	float pesoA; // peso acumulado
	float pesoB;
	float beneficio; // valor acumulado
	float benef_est; // prioridad
	float cogidos;
};
bool operator>(Nodo const& a, Nodo const& b) {
	return a.benef_est > b.benef_est;
}

bool comparador(Cancion const &a, Cancion const &b) {
	return a.puntuacion / a.duracion > b.puntuacion / b.duracion;
}

// estrategia voraz, para calcular la estimación
float calculo_voraz(vector<Cancion> const& objetos, float M, int k,
	float peso, float beneficio) {
	float hueco = (M*2) - peso;
	float estimacion = beneficio;
	int j = k + 1;
	while (j < objetos.size() && objetos[j].duracion <= hueco) {
		// podemos coger el objeto j entero
		hueco -= objetos[j].duracion;
		estimacion += objetos[j].puntuacion;
		++j;
	}
	if (j < objetos.size()) {
		estimacion += (hueco / objetos[j].duracion) * objetos[j].puntuacion;
	}
	

	return estimacion;
}

// objetos ordenados de mayor a menor valor/peso
void mochila_rp(vector<Cancion> const& objetos, float M,
	vector<bool> & sol_mejor, float & benef_mejor, float &cogidos) {
	size_t N = objetos.size();
	// se genera la raíz
	Nodo Y;
	Y.solA = vector<bool>(N);
	Y.solB = vector<bool>(N);
	Y.k = -1;
	Y.pesoA = Y.pesoB = Y.beneficio = 0;
	Y.benef_est = calculo_voraz(objetos, M, Y.k, Y.pesoA + Y.pesoB, Y.beneficio);
	Y.cogidos = 0;
	PriorityQueue<Nodo, std::greater<Nodo>> cola;
	cola.push(Y);
	benef_mejor = -1;
	// búsqueda mientras pueda haber algo mejor
	while (!cola.empty() && cola.top().benef_est > benef_mejor) {
		Y = cola.top(); cola.pop();
		Nodo X(Y);
		++X.k;
		// probamos a meter el objeto en la cinta A
		if (Y.pesoA + objetos[X.k].duracion <= M) {
			X.pesoA = Y.pesoA + objetos[X.k].duracion;
			X.solA[X.k] = true;
			X.beneficio = Y.beneficio + objetos[X.k].puntuacion;
			X.benef_est = Y.benef_est;
			X.cogidos = Y.cogidos + 1;
			if (X.k == N-1) {
				benef_mejor = X.beneficio; cogidos = X.cogidos;
			}
			else { cola.push(X); }
		}	
		

		// probamos a meter el objeto en la cinta B
		if (Y.pesoB + objetos[X.k].duracion <= M) {
			X.pesoB = Y.pesoB + objetos[X.k].duracion;
			X.pesoA = Y.pesoA;
			X.solA[X.k] = false;
			X.solB[X.k] = true;		
			X.beneficio = Y.beneficio + objetos[X.k].puntuacion;
			X.benef_est = Y.benef_est;
			X.cogidos = Y.cogidos + 1;
			if (X.k == N - 1) {
				benef_mejor = X.beneficio; cogidos = X.cogidos;
			}
			else { cola.push(X); }
		}
		
		X.benef_est = calculo_voraz(objetos, M, X.k, Y.pesoA + Y.pesoB, Y.beneficio);
		// probar a no meter el objeto		
		if (X.benef_est > benef_mejor) {
			X.pesoA = Y.pesoA; X.pesoB = Y.pesoB; X.beneficio = Y.beneficio;
			X.cogidos = Y.cogidos;
			X.solA[X.k] = false;
			X.solB[X.k] = false;
			if (X.k == N-1) {
				benef_mejor = X.beneficio; cogidos = X.cogidos;
			}
			else { cola.push(X); }
		}
	}
}

bool resuelveCaso() {
	int N, duracion;
	cin >> N >> duracion;
	if (N == 0)return false;
	std::vector<Cancion> canc(N);
	
	for (int i = 0; i < N; i++) {
		cin >> canc[i].duracion >> canc[i].puntuacion;
	}
	//Ordenamos el vector
	sort(canc.begin(), canc.end(), comparador);

	vector<bool> sol_mejor;
	float benef_mejor, cogidos;

	mochila_rp(canc, duracion, sol_mejor, benef_mejor, cogidos);
	cout << benef_mejor << endl;
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