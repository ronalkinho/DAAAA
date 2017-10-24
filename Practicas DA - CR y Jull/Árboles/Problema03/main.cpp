// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Idea para resolverlo:
Crear arbol AVL cuya clave sea la palabra, definir el comparador para que se ordene el arbol alfabeticamente,
es decir, que compare las cadenas para sacar cual es la menor (que va antes en el diccionario), como valor creamos
lista de enteros a la cual añadimos las lineas en las que se encuentra la palabra, dicha linea se le pasa como
parametro a la funcion, si dicha palabra ya se habia encontrado antes en la linea entonces ya contendrá en
su lista el numero de la linea actual por lo que no se añade de nuevo
Para mostrarla solo hay que hacer una funcion de recorrido con un iterador del AVL y se muestra la lista de enteros
sin mas
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <string>
#include "TreeMap_AVL.h"

using namespace std;

void referencias(TreeMap<string, list<int>> & a, int linea){
	string cadena;
	getline(std::cin, cadena);
	std::string delimiter = " ";
	size_t pos = 0;
	std::string token;
	while ((pos = cadena.find(delimiter)) != std::string::npos) {
		token = cadena.substr(0, pos);
		std::transform(token.begin(), token.end(), token.begin(), ::tolower);
		if (token.length() > 2){
			if (a[token].empty() || a[token].back() != linea)
				a[token].push_back(linea);
		}
		cadena.erase(0, pos + delimiter.length());
	}
	std::transform(cadena.begin(), cadena.end(), cadena.begin(), ::tolower);
	if (cadena.length() > 2){
		if (a[cadena].empty() || a[cadena].back() != linea)
			a[cadena].push_back(linea);
	}
}

//Caso 1 
/*
Los árboles RB ofrecen un peor caso con tiempo garantizado para la inserción, el borrado y la búsqueda.
No es esto únicamente lo que los hace valiosos en aplicaciones sensibles al tiempo como las aplicaciones
en tiempo real, sino que además son apreciados para la construcción de bloques en otras estructuras de
datos que garantizan un peor caso.

El árbol AVL es otro tipo de estructura con O(log n) tiempo de búsqueda, inserción y borrado.
Está equilibrado de forma más rígida que los árboles rojo-negro, lo que provoca que la inserción
y el borrado sean más lentos que el RB pero la búsqueda y la devolución del resultado de la misma más veloz.
*/
// resuelve un caso de prueba
void resuelveCaso(int l) {
	TreeMap<string, list<int>> a;
	std::string c;
	getline(std::cin, c);
	for (int i = 0; i < l; ++i){
		referencias(a, i + 1);
	}
	//Mostrar resultados
	TreeMap<string, list<int>>::Iterator it = a.begin();
	list<int>::const_iterator itL;
	while (it != a.end()){
		itL = (*it).valor.cbegin();
		std::cout << (*it).clave;
		while (itL != (*it).valor.cend()){
			std::cout << " " << (*itL);
			itL++;
		}
		std::cout << endl;
		it++;
	}
	std::cout << "----" << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int lineas;
	std::cin >> lineas;
	while (lineas != 0){
		resuelveCaso(lineas);
		std::cin >> lineas;
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}