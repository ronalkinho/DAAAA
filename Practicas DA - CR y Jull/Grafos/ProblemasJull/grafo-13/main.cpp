
//  NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
using namespace std;


// comentario sobre la solución y su coste
bool resuelveCaso() {
	int N, caras, s, e, ini, fin, sig, aux, max;
	bool encontrado = false;
	cin >> N >> caras >> s >> e;
	

	if (N == 0 && caras == 0 && s == 0 && e == 0) // no hay más casos
		return false;
	max = N*N;
	vector<bool> marked(max + 1, false);     // marked[v] = hay camino s-v?
	vector<int> atajos(max + 1, 0);
	//vector<int> escaleras(max + 1, 0);
	vector<int> distTo(max + 1, 0);   // distTo[v] = número de aristas en el camino s-v más corto


	// si no hay centinela
	 //if (!cin)
	    //return false;
	 // leer resto del caso

	for (int i = 0; i < s+e; ++i){
		cin >> ini >> fin;
		atajos[ini] = fin;
	}

	/*for (int i = 0; i < e; ++i){
		cin >> ini >> fin;
		escaleras[ini] = fin;
	}*/

	 queue<int> q;
	 distTo[1] = 0;
	 marked[1] = true;
	 q.push(1);
	 while (!encontrado && !q.empty()) {
		 int v = q.front(); 
		 if (v == max){
			 encontrado = true;
		 }
		 else{
			 q.pop();

			 for (int i = 1; i <= caras; ++i) {
				 sig = v + i;
				 if (sig <= max){

					 if (!marked[sig]) {
						 if (atajos[sig] != 0){
							 aux = atajos[sig];
							 distTo[aux] = distTo[v] + 1;
							 marked[aux] = true;
							 marked[sig] = true;
							 q.push(aux);
						 }
						 else if (atajos[sig] != 0){
							 aux = atajos[sig];
							 distTo[aux] = distTo[v] + 1;
							 marked[aux] = true;
							 marked[sig] = true;
							 q.push(aux);
						 }
						 else{
							 distTo[sig] = distTo[v] + 1;
							 marked[sig] = true;
							 q.push(sig);
						 }

					 }
				 }
			 }
		 }
	
	 }
	// resolver caso
	 cout << distTo[max] << endl;
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
