//TAIS04 - Fernando Miñambres y Juan José Prieto


#include <iostream>
#include <fstream>
#include <list>

using namespace std;

#include "PriorityQueue.h"

struct Usuario{
	int identificador;
	int periodo;
	int periodoAcu;
	bool operator<(const Usuario& rhs) const {
		return rhs.periodoAcu > this->periodoAcu || (rhs.periodoAcu == this->periodoAcu && rhs.identificador > this->identificador);
	}
};

//Función que determina a qué destinatario se dirige el envío en función de su periodo. Para ello vamos acumulando el periodo en una variable y 
// vamos comparando entre los usuarios más prioritarios (menor periodo acumulado de envío).
//Se utiliza una cola de prioridad con los datos de entrada y una lista en la que se van almacenando los identificadores a los que se va a enviar.


//El coste de la función es O(K log (n)) siendo K el número de envíos y n el número de usuarios registrados.

void envios(PriorityQueue<Usuario>cola, int K){

	list<Usuario> solucion;

	while (K > 0){
		Usuario aux = cola.top();
		cola.pop();
		if (!cola.empty())
			//Comprobamos cuál es el usuario más prioritario (menor período acumulado)
		if (aux.periodoAcu <= cola.top().periodoAcu){
			solucion.push_back(aux);
			aux.periodoAcu += aux.periodo;
			cola.push(aux);
		}
		else{
			Usuario aux2 = cola.top();
			solucion.push_back(aux2);
			aux2.periodoAcu += aux2.periodo;
			cola.push(aux);
			cola.push(aux2);
		}
		else{
			solucion.push_back(aux);
			aux.periodoAcu += aux.periodo;
			cola.push(aux);
		}
		K--;
	}
	//Mostramos por pantalla los identificadores a los que se envía información
	for (auto u : solucion){
		cout << u.identificador << endl;
	}
}


bool resuelveCaso(){

	int nUsuarios, K;
	cin >> nUsuarios;

	if (nUsuarios == 0){ return false; }

	PriorityQueue<Usuario>colaUsuarios;
	//Leemos los datos de entrada y los almacenamos en la cola de prioridad
	for (int i = 0; i < nUsuarios; i++){
		Usuario u;
		cin >> u.identificador >> u.periodo;
		u.periodoAcu = u.periodo;
		colaUsuarios.push(u);
	}
	cin >> K;

	envios(colaUsuarios, K);

	cout << "----" << endl;
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
	system("pause");
#endif

	return 0;
}