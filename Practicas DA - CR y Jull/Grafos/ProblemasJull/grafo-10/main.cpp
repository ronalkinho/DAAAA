
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "ConjuntosDisjuntos.h"
using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N, relaciones,v1,v2,c1,c2,aux1,aux2;
	cin >> N;
	
	//if (N==0) // no hay más casos
		//return false;

	// si no hay centinela
	if (!cin)
	   return false;
	ConjuntosDisjuntos c(N);
	// leer resto del caso
	cin >> relaciones;
	for (int i = 0; i < relaciones; ++i){
		cin >> v1 >> v2;
		if (i == 0){
			c1 = v1;
			c2 = v2;

		}
		else{
			aux1 = c.buscar(v1);
			aux2 = c.buscar(v2);
			if (aux1 == c1){
				c.unir(v2, c2);	
			}
			if (aux1 == c2){
				c.unir(v2, c1);
			}
			if (aux2 == c1){
				c.unir(v1, c2);
			}
			if (aux2 == c2){
				c.unir(v1, c1);
			}
			//c.unir(v2, 3);
			/*aux1 = c.buscar(v1);
			aux2 = c.buscar(v2);
			if (aux1 == v1)
				c.unir(v1, v1);
			if (aux2 == v2)
				c.unir(v2, v2);*/

		}
			
	}
	
	cout << c.count();
	// resolver caso
	if (c.count() == 2)
		cout << "SI" << endl;
	else
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
