// TAIS04 Fernando Miñambres y Juan José Prieto

// El problema se resuelve almacenando el precio por libro en un vector ordenado de mayor a menor precio
// Se realiza un bucle sobre todo el tamaño del vector en el que cada 3 posiciones se guarda el valor de la posicion del vector
// en la variable descuentoMax.
//
//El coste de la función es O(N log N + N) siendo N el número de elementos del vector. El coste O(N log N) corresponde a la
// operacion sort sobre el vector y O(N) porque se recorre todo el vector.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int descuento3por2(vector<int> & vec){
	int descuentoMax = 0,pos = 0;

	sort(vec.begin(), vec.end(), greater<int>());

	for (int i = 0; i < vec.size(); i++){
		if (pos == 2){
			descuentoMax += vec[i];
			pos = 0;
		}
		else{
			pos++;
		}
	}
	return descuentoMax;
}

bool resuelveCaso(){
	int nLibros;
	cin >> nLibros;
	if (!cin)return false;
	vector<int> libros(nLibros);

	for (int i = 0; i < libros.size(); i++){
		cin >> libros[i];
	}
	
	cout << descuento3por2(libros) << endl;

	return true;
}

int main(){

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()){

	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}