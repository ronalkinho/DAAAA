
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int islas, puentes, ini, fin, dist;
	bool terminado = false;
	
	cin >> islas;

	//if (N == 0) // no hay más casos
	//	return false;

	// si no hay centinela
	 if (!cin)
	    return false;
	 cin >> puentes;
	 PriorityQueue<Arista<int>> menorPuentes(puentes);
	 //vector<bool> islasVisitadas(islas + 1, false);
	 ConjuntosDisjuntos conjPuentes(islas + 1);
	 queue<Arista<int>> totalPuentes;;
	 // leer resto del caso
	 for (int i = 0; i < puentes;++i){
		 cin >> ini >> fin >> dist;
		 Arista<int> a(ini, fin, dist);
		 menorPuentes.push(a);
	 }

	// resolver caso
	 while(!menorPuentes.empty() && totalPuentes.size() < islas-1){
		 Arista<int> a = menorPuentes.top();
		 int v = a.uno(), w = a.otro(v);
		 if (conjPuentes.buscar(v) != conjPuentes.buscar(w)) {
			 conjPuentes.unir(v, w);
			 totalPuentes.push(a);
		 }
		 menorPuentes.pop();
	 }
	 int coste = 0;
	 if (conjPuentes.count() == 2){
		 while (!totalPuentes.empty()){
			 Arista<int> a = totalPuentes.front();
			 coste += a.valor();
			 totalPuentes.pop();
		 }
		 cout << coste << endl;
	 }
	 else{
		 cout << "No hay puentes suficientes" << endl;
	 }

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
