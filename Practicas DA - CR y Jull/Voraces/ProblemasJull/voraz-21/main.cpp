
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N, L, pos, num=0;
	
	cin >> N;

	if (N == 0) // no hay más casos
		return false;

	// si no hay centinela
	 //if (!cin)
	   // return false;
	PriorityQueue<int> altura(N);
	PriorityQueue<int> esquis(N);
	 
	 for (int i = 0; i < N; ++i){
		 cin >> pos;
		 altura.push(pos);
	 }
	 for (int i = 0; i < N; ++i){
		 cin >> pos;
		 esquis.push(pos);
	 }
	// leer resto del caso

	// resolver caso
	 
	 while (!altura.empty() ) {
		 num += abs(altura.top() - esquis.top());
		 altura.pop();
		 esquis.pop();
	 }
	 cout << num << endl;
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
