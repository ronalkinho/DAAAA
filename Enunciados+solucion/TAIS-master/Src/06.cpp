// TAIS03 LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;

typedef struct{
	string nombre;
	int gravedad;
	int orden;
}tPaciente;

class compara{
public:
	bool operator()(tPaciente &p1, tPaciente &p2){
		if (p1.gravedad > p2.gravedad)
			return true;
		else if (p1.gravedad == p2.gravedad && p1.orden < p2.orden)
			return true;
		else
			return false;
	}
};

// O(n), siendo n el numero de pacientes 
bool resuelveCaso(){
	int n;
	cin >> n;
	if (n == 0)
		return false;

	PriorityQueue<tPaciente,compara> pq;
	string ac;

	for (int i = 0; i < n; i++)
	{
		cin >> ac;
		tPaciente paciente;
		if (ac == "I"){
			cin >> paciente.nombre >> paciente.gravedad;
			paciente.orden = i;
			pq.push(paciente);
		}
		else if (ac == "A"){
			paciente = pq.top();
			pq.pop();
			cout << paciente.nombre << endl;
		}
	}
	cout << "----" << endl;
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