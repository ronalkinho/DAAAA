//TAIS04 Fernando Miñambres y Juan José Prieto
//
// El problema se resuelve utilizando un arbol para guardar los codigos y un
// vector para calcular recursivamente las posibilidades de formar un codigo
// desde el dígito i hasta el dígito j. Siendo:
// Vector[i] = Vector[i] + Vector[i-1];   Si i == j
// Vector[j] = Vector[j] + Vector[i-1];   En otro caso
// Inicializamos con Vector[0] = 1;
//
// La solucion para nuestro codigo estará en Vector[numero de dígitos];
//
// El coste de la función es de O(n * 3 log M) en tiempo y O(n) en espacio adicional, 
// siendo n el número de dígitos del mensaje y M el numero de códigos. Ya que 
// para cada dígito recorremos los 3 siguientes y los buscamos en el árbol.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <limits> 
#include <climits>
#include <string>
#include <array>
#include <time.h>
#include "Matriz.h"
#include "TreeMap_AVL.h"

using namespace std;
int posiblesCodigos(TreeMap<string, int> const &codigos, string const &codigo) {
	int n = codigo.size() - 1;
	vector<long long int> posiblidades(n + 1, 0);


	posiblidades[0] = 1;
	string numero = "0";
	for (int i = 1; i <= n; i++) {
		numero = codigo.substr(i, 1);
		if (numero == "0") {
			posiblidades[i] = posiblidades[i - 1];
		}
		else if (codigos.contains(numero)) {
			posiblidades[i] = (posiblidades[i] + posiblidades[i - 1]) % 1000000007;
		}
		if (numero != "0") {
			int j = i + 1;
			while (j <= n && j < i + 4) {
				numero = codigo.substr(i, j - i + 1);
				if (codigos.contains(numero)) {
					posiblidades[j] = (posiblidades[j] + posiblidades[i - 1]) % 1000000007;
				}
				j++;

			}
		}
	}

	return posiblidades[n];
}

bool resuelveCaso() {
	int numSimbolos;
	cin >> numSimbolos;
	if (numSimbolos == 0)
		return false;

	TreeMap<string, int> codigos;

	for (int i = 0; i < numSimbolos; i++) {
		string num;
		cin >> num;
		codigos.insert(num, 0);
	}

	string cod;
	cin >> cod;
	string codigo = "0";
	codigo.append(cod);
	cout << posiblesCodigos(codigos, codigo) << endl;

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