// TAIS 03, LUIS ARROYO Y ZHIHAO ZHENG
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

// O(NlogN), siendo N el numero de edificios(entre 1 y 100000)
void resuelveCaso(){

	int N, V;
	cin >> N >> V;

	int nCoche = 0;
	int p;
	vector<int> pilas(N);
	for (int i = 0; i < N; i++)
	{
		cin >> p;
		pilas[i] = p;
	}

	sort(pilas.begin(), pilas.end());

	int i = 0;
	int j = pilas.size() - 1;

	while (i < j){
		if (pilas[i] + pilas[j] >= V){
			nCoche++;
			i++;
			j--;
		}
		else {
			i++;
		}
	}
	cout << nCoche << endl;
	
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	
	for (int i = 0; i < numCasos; i++)
	{
		resuelveCaso();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}