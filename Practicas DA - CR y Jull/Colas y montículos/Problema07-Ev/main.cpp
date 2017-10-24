// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

/*
Para solucionar el problema lo que hacemos es en un principio crear la cola con todos los elementos iniciales, con sus prioridades
y una variable tiempo que medir� el avance en la linea temporal para el env�o de paquetes y que nos har� saber quien es el primero
que recibe el paquete enviado.
Con la cola inicial creada simplemente vamos leyendo el primer elemento de la cola, que ser� el que ha recibido el paquete actual,
lo mostramos y lo volvemos a introducir en la cola pero en el tiempo se le suma su prioridad, de esta manera al hacer el push se 
colocar� en su lugar correcto en el orden de recepci�n de paquetes.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

typedef struct {
	int id;
	int tiempo;
	int prio;
} Dato;

/*
Redefinici�n del operador < para la comparaci�n en la cola de prioridad de 2 elementos de tipo Dato

Coste: constante de O(1)
*/
bool operator <(Dato a, Dato b){
	if (a.tiempo == b.tiempo)
		return a.id < b.id;
	else
		return a.tiempo < b.tiempo;
}

/*
Funci�n para la creaci�n de la cola inicial de identificadores con sus respectivos campos, se devuelve la cola ya ordenada

Coste: lineal en el n�mero de elementos de la cola y logar�tmica en la ordenaci�n del elemento al introducirlo en la cola,
por tanto tiene un coste de N log(N) siendo N el n�mero de elementos
*/
PriorityQueue<Dato> creaCola(int n){
	PriorityQueue<Dato> p(n);
	int id, prio;
	Dato d;
	for (int i = 0; i < n; ++i){
		std::cin >> id;
		std::cin >> prio;
		d.id = id;
		d.tiempo = prio;
		d.prio = prio;
		p.push(d);
	}
	return p;
}

//Caso 1
/*
Funci�n para el recorrido de la cola y actualizaci�n de la unidad de tiempo de cada elemento, de esta manera a la cabeza de la cola
siempre se encuentra el elemento que primero recibe el paquede enviado, adem�s lo muestra.

Coste: es lineal en el n�mero de mensajes o paquetes a enviar y logar�tmico en el n�mero de elementos de la cola, por tanto tiene
un coste de M log(N) siendo M el n�mero de mensajes y N el n�mero de elementos de la cola 
*/
void resuelveCaso(PriorityQueue<Dato> &p, int msgs) {
	Dato d;
	//Mostrar
	for (int i = 0; i < msgs; ++i){
		d = p.top();
		p.pop();
		std::cout << d.id << endl;
		d.tiempo += d.prio;
		p.push(d);
	}
	std::cout << "----" << endl;
}

int main() {
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int numIds, numMsg;
	PriorityQueue<Dato> p;
	std::cin >> numIds;
	while (numIds != 0){
		p = creaCola(numIds);
		std::cin >> numMsg;
		resuelveCaso(p, numMsg);
		std::cin >> numIds;
	}
	
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