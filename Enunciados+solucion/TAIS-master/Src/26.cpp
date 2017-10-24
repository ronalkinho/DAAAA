// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

struct hamburguesa
{
	int L;
	int R;
};

class comparator{
public:
	bool operator()(const hamburguesa e1, const hamburguesa e2){
		if (e1.L < e2.L){
			return true;
		} else {
			return false;
		}
	}
};

void leerRestaurantes(PriorityQueue<hamburguesa, comparator> &colaHamburguesa, int L, int N) {
	hamburguesa aux;
	int p, r;
	for (int i = 0; i < N; i++)
	{
		cin >> p >> r;
		if (p - r < 0){
			aux.L = 0;
		}
		else {
			aux.L = p - r;
		}
		if (p + r > L){
			aux.R = L;
		}
		else {
			aux.R = p + r;
		}
		colaHamburguesa.push(aux);
	}
}

// O(NlogN), siendo N el numero de hamburguserias(entre 1 y 100000)
bool resuelveCaso(){

	int L, N;
	cin >> L >> N;

	if (!cin) return false;


	PriorityQueue<hamburguesa, comparator> colaHamburguesa;
	leerRestaurantes(colaHamburguesa, L, N);

	int inicio = 0;
	int numRest = 0;
	int maxRange = 0;
	bool hueco = false;
	
	while (!colaHamburguesa.empty() && !hueco)
	{
		if (colaHamburguesa.top().L > maxRange){
			hueco = true;
		}
		else {
			if (colaHamburguesa.top().L <= inicio){
				if (colaHamburguesa.top().R > maxRange){
					if (maxRange != inicio)
						numRest++;
					maxRange = colaHamburguesa.top().R;
				}
				else {
					numRest++;
				}
				colaHamburguesa.pop();
			}
			else {
				inicio = maxRange;
			}
		}
	}

	if (hueco || maxRange < L)
		cout << -1 << endl;
	else
		cout << numRest << endl;

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