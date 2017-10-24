#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

typedef struct{
	int id;
	int periodo;
	int prioridad;
}tUsuario;

class compare{
public:
	bool operator()(tUsuario u1, tUsuario u2){
		return u1.prioridad <= u2.prioridad;
	}
};

void leerCola(PriorityQueue<tUsuario, compare> &colap, int n){
	tUsuario usuario;
	for (int i = 0; i < n; i++)
	{
		cin >> usuario.id;
		cin >> usuario.periodo;
		usuario.prioridad = usuario.periodo;
		colap.push(usuario);
	}
}

bool resuelveCaso(){
	int n;
	cin >> n;
	if (n == 0)
		return false;
	PriorityQueue<tUsuario, compare> colap;
	leerCola(colap, n);

	int numEnvio;
	cin >> numEnvio;
	tUsuario usuario;
	for (int i = 0; i < numEnvio; i++)
	{
		usuario = colap.top();
		colap.pop();
		cout << usuario.id << endl;
		usuario.prioridad += usuario.periodo;
		colap.push(usuario);
	}
	return true;
}

int main(){

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