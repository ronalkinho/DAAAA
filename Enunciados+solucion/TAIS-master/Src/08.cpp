#include <iostream>
#include <fstream>
#include "mediana.h"
using namespace std;

bool resuelveCaso(){
	int n;
	cin >> n;
	if (n == 0)
		return false;

	int p;
	Mediana cola;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		cola.push(p, i);
		
		cout << cola.getMedia(i);
		if (i < n)
			cout << " ";
	}
	cout << endl;

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