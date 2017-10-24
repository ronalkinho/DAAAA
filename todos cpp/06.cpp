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

class Prio{
private:
	int gravedad;
	int orden;

public:
	Prio(){};
	Prio(int g, int o) : gravedad(g), orden(o){};

	friend bool operator>(Prio a, Prio b);
};

bool operator>(Prio a, Prio b){
	if (a.gravedad > b.gravedad) return true;
	else if (a.gravedad == b.gravedad){
		if (a.orden < b.orden) return true;
		else return false;
	}
	else return false;
}

// resuelve un caso de prueba
void resuelveCaso(int numero) {
	IndexPQ<Prio, std::greater<Prio>> pq(numero);
	vector<string> nombres(numero + 1);
	cin.get();
	for (int i = 0; i < numero; i++)
	{
		string l;
		getline(cin, l);
		istringstream iss(l);
		vector<string> v;
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(v));
		if (v.size() > 0)
		{
			if (v[0] == "I")
			{
				int prio = std::stoi(v[2]);
				Prio p(prio, i);
				pq.push(i, p);
				nombres[i] = v[1];
			}
			else if (v[0] == "A")
			{
				IndexPQ<Prio, std::greater<Prio>>::Par p = pq.top();
				pq.pop();
				size_t e = p.elem;
				cout << nombres[e] << endl;
			}
		}
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