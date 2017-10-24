
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "ConjuntosDisjuntos.h"
using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N, aristas, v1,v2;
	cin >> N;
	
	
	//if (N == 0) // no hay más casos
	//	return false;

	// si no hay centinela
	 if (!cin)
	    return false;
	 // leer resto del caso
	 ConjuntosDisjuntos c(N);
	 cin >> aristas;
	
	for (int i = 0; i < aristas; i++){
		cin >> v1 >> v2;
		c.unir(v1, v2);
	}
	 

	// resolver caso
	 if (c.count()==1 && N>aristas){
		 cout << "SI" << endl;
	 }else
		 cout << "NO" << endl;
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
