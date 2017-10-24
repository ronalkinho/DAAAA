// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
#include <iterator>
#include <functional>
using namespace std;

#include "IndexPQ.h"

class Id{
public:

	int id;
	int periodo;
	int prioridad;

	Id(){};
	Id(int i, int p, int pr) : id(i), periodo(p), prioridad(pr){};

	friend bool operator<(Id a, Id b);
};

bool operator<(Id a, Id b){
	if (a.prioridad < b.prioridad) return true;
	else if (a.prioridad == b.prioridad){
		if (a.id < b.id) return true;
		else return false;
	}
	else return false;
}

// resuelve un caso de prueba
void resuelveCaso(int numero) {
	IndexPQ<Id, std::less<Id>> pq(numero);
	//vector<Id> ids(numero + 1);
	cin.get();
	for (int i = 0; i < numero; i++)
	{
		int id, periodo;
		cin >> id;
		cin >> periodo;
		Id usuario(id, periodo, periodo);
		//ids[i] = usuario;
		pq.push(i, usuario);
	}
	int envios = 0;
	cin >> envios;
	for (int i = 0; i < envios; i++){
		IndexPQ<Id, std::less<Id>>::Par p = pq.top();
		//cout << ids[p.elem].id << endl;
		cout << p.prioridad.id << endl;
		p.prioridad.prioridad = p.prioridad.prioridad + p.prioridad.periodo;
		pq.update(p.elem, p.prioridad);
	}
	cout << "----" << endl;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numero = 0;
	cin >> numero;
	while(numero != 0){
		resuelveCaso(numero);
		cin >> numero;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}