
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N, numPilas, min, v, num = 0;
	cin >> N;

	//if (N == 0) // no hay más casos
	//	return false;

	// si no hay centinela
	// if (!cin)
	//    return false;

	// leer resto del caso
	for (int i = 0; i < N; ++i){
		cin >> numPilas >> min;
		PriorityQueue<int, greater<int>> vol1(numPilas);
		PriorityQueue<int> vol2(numPilas);
		num = 0;
		while (num < numPilas){
			cin >> v;
			vol1.push(v);
			vol2.push(v);
			num++;
			
		}
		num = 0;
		while (numPilas>1){
			if (vol1.top() + vol2.top() >= min){
				numPilas -= 2;
				vol1.pop();
				vol2.pop();
				num++;
			}
			else{
				--numPilas;
				vol2.pop();
			}

		}
		cout << num << endl;
	}
	// resolver caso

	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
