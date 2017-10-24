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
using namespace std;

#include "BinTree.h"
#include "TreeMap_AVL.h"

// resuelve un caso de prueba
void resuelveCaso(int lineas) {
	TreeMap<string, vector<int>> t;
	cin.get();
	for (int i = 0; i < lineas; i++)
	{
		TreeMap<string, int> comp;
		string l;
		getline(cin, l);
		istringstream iss(l);
		vector<string> v;
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(v));
		vector<string>::const_iterator cit = v.cbegin();
		while (cit != v.cend()){
			string p = *cit;
			transform(p.begin(), p.end(), p.begin(), ::tolower);
			if (p.size() > 2 && !comp.contains(p))
			{
				comp[p] = i;
				vector<int> vint = t[p];
				vint.push_back(i + 1);
				t[p] = vint;
			}
			cit++;
		}
	}
	TreeMap<string, vector<int>>::Iterator it = t.begin();
	while (it != t.end()){
		TreeMap<string, vector<int>>::ClaveValor cv = *it;
		string palabra = cv.clave;
		vector<int> vint = cv.valor;
		vector<int>::const_iterator cit = vint.cbegin();
		cout << palabra << " ";
		while (cit != vint.cend())
		{
			cout << *cit << " ";
			cit++;
		}
		cout << endl;
		it++;
	}
	cout << "----" << endl;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int lineas;
	cin >> lineas;
	while (lineas != 0){
		resuelveCaso(lineas);
		cin >> lineas;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}