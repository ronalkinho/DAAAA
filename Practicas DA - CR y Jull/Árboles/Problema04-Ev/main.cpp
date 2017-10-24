// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Para solucionar el problema recorremos la lista de emisiones, vamos creando el arbol y contando las emisiones seguidas
que se producen, hasta que se repite un capitulo, entonces se actualiza el numero maximo de dias sin repeticion (si procede),
se establece cuando se ha efectuado la ultima repeticion y se actualiza la emision del capitulo en el arbol, ademas de decir
que ha habido repeticion en la serie de capitulos del caso.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "TreeMap_RB.h"

using namespace std;

/*
Coste: tiene un coste N log(M) siendo N el numero de capitulos emitidos en el caso (contando las repeticiones)
y M el numero de capitulos sin repeticion que se hen emitido 
*/
int capitulos(int totalC){
	TreeMap<int, int> a;
	int maxDias = 0, cap=0, emision=1, ultRep=0;
	bool rep = false;
	while (emision <= totalC){
		std::cin >> cap;
		if (a.contains(cap)){
			if (a.at(cap) >= max(ultRep, 1)){
				if ((emision - max(ultRep, 1)) > maxDias)
					maxDias = emision - max(ultRep, 1);
				ultRep = a.at(cap) + 1;
			}
			else{
				if ((emision - max(ultRep, 1) + 1) > maxDias)
					maxDias = emision - max(ultRep, 1) + 1;
			}
			a.insert(cap, emision);
			rep = true;
		}
		else{
			a.insert(cap, emision);
		}
		emision++;
	}
	//emision--;
	if (!rep)
		return emision-1;
	if ((emision - ultRep) > maxDias)
		return emision - ultRep;
	else
		return maxDias;
}


//Caso 1
// resuelve un caso de prueba
void resuelveCaso() {
	int n;
	std::cin >> n;
	std::cout << capitulos(n) << endl;
}

int main() {
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}

//Caso 2
/*
bool resuelveCaso() {
	h leer los datos de la entrada i
		if (caso especial)
			return false;
	Solucion sol = resolver(datos);
	h escribir sol i
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
}*/

//Caso 3
/*
bool resuelveCaso() {
	h leer los datos de la entrada i
		if (!cin) // fin de la entrada
			return false;
	Solucion sol = resolver(datos);
	h escribir sol i
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
*/