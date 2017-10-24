#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "TreeMap_AVL.h"
using namespace std;

void resuelve(TreeMap<string, vector<int>> treemap){
	for (auto a : treemap){
		cout << a.clave;
		for (auto i = 0; i < a.valor.size(); i++)
		{
			cout << " " << a.valor[i];
		}
		cout << endl;
	}
}

void construirArbol(TreeMap<string, vector<int>> &treemap, int n){
	string texto;
	cin.get();
	for (int i = 1; i <= n; i++)
	{
		getline(cin, texto);
		string palabra;
		for (auto j = 0; j <= texto.size(); j++)
		{
			if (isalpha(texto[j])) {
				palabra.push_back(tolower(texto[j]));
			}
			else{
				if (palabra.size() > 2){
					vector<int> & tmp = treemap[palabra];
					if (tmp.empty() || tmp.back() != i){
						tmp.push_back(i);
					}
				}
				palabra.clear();
			}
		}
	}
}

bool resuelveCaso(){
	int n;
	cin >> n;
	if (n == 0)
		return false;
	TreeMap<string, vector<int>> treemap;
	construirArbol(treemap, n);

	resuelve(treemap);
	cout << "----" << endl;

	return true;
}

int main(){

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()){};

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}