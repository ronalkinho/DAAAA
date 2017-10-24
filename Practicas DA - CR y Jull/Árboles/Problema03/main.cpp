// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

/*
Idea para resolverlo:
Crear arbol AVL cuya clave sea la palabra, definir el comparador para que se ordene el arbol alfabeticamente,
es decir, que compare las cadenas para sacar cual es la menor (que va antes en el diccionario), como valor creamos
lista de enteros a la cual a�adimos las lineas en las que se encuentra la palabra, dicha linea se le pasa como
parametro a la funcion, si dicha palabra ya se habia encontrado antes en la linea entonces ya contendr� en
su lista el numero de la linea actual por lo que no se a�ade de nuevo
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
Los �rboles RB ofrecen un peor caso con tiempo garantizado para la inserci�n, el borrado y la b�squeda.
No es esto �nicamente lo que los hace valiosos en aplicaciones sensibles al tiempo como las aplicaciones
en tiempo real, sino que adem�s son apreciados para la construcci�n de bloques en otras estructuras de
datos que garantizan un peor caso.

El �rbol AVL es otro tipo de estructura con O(log n) tiempo de b�squeda, inserci�n y borrado.
Est� equilibrado de forma m�s r�gida que los �rboles rojo-negro, lo que provoca que la inserci�n
y el borrado sean m�s lentos que el RB pero la b�squeda y la devoluci�n del resultado de la misma m�s veloz.
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