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

#include "PriorityQueue.h"

// resuelve un caso de prueba
void resuelveCaso(int numero) {
	PriorityQueue<int, std::greater<int>> lessThanA;
	int a = 0;
	int b = 0;
	PriorityQueue<int, std::less<int>> moreThanB;
	for (int i = 0; i < numero; i++)
	{
		int n;
		cin >> n;
		if (a == 0 && b == 0) a = n;
		else if (b == 0){
			cout << " ";
			if (n < a){
				b = a;
				a = n;
			}
			else b = n;
		}
		else if (a != 0 && b != 0){
			cout << " ";
			if (n > b){
				moreThanB.push(n);
				if (moreThanB.size() > lessThanA.size() + 1)
				{
					lessThanA.push(a);
					a = b;
					b = moreThanB.top();
					moreThanB.pop();
				}
			}
			else if (n < a){
				lessThanA.push(n);
				if (lessThanA.size() > moreThanB.size() + 1)
				{
					moreThanB.push(b);
					b = a;
					a = lessThanA.top();
					lessThanA.pop();
				}
			}
			else{
				if (moreThanB.size() > lessThanA.size())
				{
					lessThanA.push(a);
					a = n;
				}
				else if (moreThanB.size() <= lessThanA.size())
				{
					moreThanB.push(b);
					b = n;
				}
			}
		}
		if ((i + 1) % 2 == 0) cout << a + b;
		else{
			if (b == 0) cout << a * 2;
			else{
				if (moreThanB.size() > lessThanA.size()) cout << b * 2;
				else cout << a * 2;
			}
		}
	}
	cout << endl;
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