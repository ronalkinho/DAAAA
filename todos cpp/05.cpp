// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;

#include "PriorityQueue.h"

int esfuerzo(const int n){
	PriorityQueue<int> cola;
	if (n == 1){
		int aux;
		cin >> aux;
		return 0;
	}
	else{
		for (int i = 0; i < n; i++){
			int num;
			cin >> num;
			cola.push(num);
		}
		int esfuerzo = 0;
		while (cola.size() > 1){
			int suma = cola.top();
			cola.pop();
			suma = suma + cola.top();
			cola.pop();
			esfuerzo = esfuerzo + suma;
			cola.push(suma);
		}
		return esfuerzo;
	}
}

// resuelve un caso de prueba
void resuelveCaso(const int n) {
	cout << esfuerzo(n) << endl;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numeros;
	std::cin >> numeros;
	cin.get();
	while (numeros != 0)
	{
		resuelveCaso(numeros);
		std::cin >> numeros;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
