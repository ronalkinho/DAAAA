//TAIS 03, Luis Arroyo y Zhihao Zheng
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include"PriorityQueue.h"



using namespace std;


struct Cancion {

	float duracionC;
	float puntuacionC;

};

struct Nodo{

	int k;
	float tiempo1; //Tiempo ocupado cara 1
	float tiempo2; //Tiempo ocupado cara 2
	float puntuacion; // Puntuación acumulada
	float puntuacionEst; // Puntuación estimada
};

class comparaCancion{
public:
	bool operator()(Cancion const& a, Cancion const& b) {
		return (a.puntuacionC/a.duracionC) > (b.puntuacionC/b.duracionC);
	}
};

bool operator>(Nodo const& a, Nodo const& b) {
	return a.puntuacionEst > b.puntuacionEst;
}

//Estrategia voraz. O(N), donde N es el número de canciones.
float calEstimacion(vector<Cancion> canciones, float espacio, int k, float tiempo, float puntuacion) {
	
	float espacioLibre = espacio - tiempo;
	
	float est = puntuacion;
	int N = canciones.size();
	int j = k + 1;


	while (j < N && canciones[j].duracionC <= espacioLibre) {
		
		espacioLibre -= canciones[j].duracionC;
		est += canciones[j].puntuacionC;
	
		j++;

	}

	if (j < canciones.size()){
		est += (espacioLibre / canciones[j].duracionC) * canciones[j].puntuacionC;
	}

	return est;
}

//O(NlogN)
void pepeCasanova(vector<Cancion> canciones, float cara1, float cara2, float &resultOptimo) {

	size_t N = canciones.size();

	Nodo Y;
	Y.k = -1;
	Y.tiempo1 = Y.tiempo2 = Y.puntuacion = 0;
	Y.puntuacionEst = calEstimacion(canciones, cara1 + cara2, Y.k, Y.tiempo1 + Y.tiempo2, Y.puntuacion);
	PriorityQueue<Nodo, greater<Nodo>> cola;

	cola.push(Y);
	
	while (!cola.empty() && cola.top().puntuacionEst > resultOptimo) {

		Y = cola.top(); cola.pop();
		Nodo X(Y);

		X.k++;

		if (Y.tiempo1 == Y.tiempo2) {
			//Probamos a meter la canción en la cara 1
			if (Y.tiempo1 + canciones[X.k].duracionC <= cara1) {
				X.tiempo1 = Y.tiempo1 + canciones[X.k].duracionC;
				X.puntuacion = Y.puntuacion + canciones[X.k].puntuacionC;
				X.puntuacionEst = Y.puntuacionEst;

				if (X.k == N - 1) {
					resultOptimo = X.puntuacion;
				}
				else {
					cola.push(X);
				}
			}
		}
		else {

			//Probamos a meter la canción en la cara 1
			if (Y.tiempo1 + canciones[X.k].duracionC <= cara1) {
				X.tiempo1 = Y.tiempo1 + canciones[X.k].duracionC;
				X.puntuacion = Y.puntuacion + canciones[X.k].puntuacionC;
				X.puntuacionEst = Y.puntuacionEst;

				if (X.k == N - 1) {
					resultOptimo = X.puntuacion;
				}
				else {
					cola.push(X);
					X.tiempo1 -= canciones[X.k].duracionC;
				}
			}

			//Probamos a meter la canción en la cara 2
			if (Y.tiempo2 + canciones[X.k].duracionC <= cara2) {
				X.tiempo2 = Y.tiempo2 + canciones[X.k].duracionC;
				X.puntuacion = Y.puntuacion + canciones[X.k].puntuacionC;
				X.puntuacionEst = Y.puntuacionEst;

				if (X.k == N - 1) {
					resultOptimo = X.puntuacion;
				}
				else {
					cola.push(X);
				}
			}
		}
		//Probamos a NO meter la canción en el casete
		X.puntuacionEst = calEstimacion(canciones, cara1 + cara2, X.k, Y.tiempo1 + Y.tiempo2, Y.puntuacion);
		if (X.puntuacionEst > resultOptimo) {
			X.puntuacion = Y.puntuacion; X.tiempo1 = Y.tiempo1; X.tiempo2 = Y.tiempo2;
			if (X.k == N - 1) {
				resultOptimo = X.puntuacion;
			}
			else {
				cola.push(X);
			}
		}

	}
}


bool resuelveCaso(){

	int N;

	cin >> N;

	if (N == 0) return false;

	float duracionCas;

	cin >> duracionCas;

	float cara1 = duracionCas;
	float cara2 = duracionCas;

	float d, p;
	vector<Cancion> canciones(N);

	for (int i = 0; i < N; i++) {
		cin >> d >> p;
		canciones[i].duracionC = d;
		canciones[i].puntuacionC = p;
	}

	sort(canciones.begin(), canciones.end(), comparaCancion());

	float resultOpt = -1;

	pepeCasanova(canciones, cara1, cara2, resultOpt);

	cout << resultOpt << endl;

	return true;

}


int main(){

#ifndef DOMJUDGE

	ifstream in("casos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());

#endif DOMJUDGE


	while (resuelveCaso());


#ifndef DOMJUDGE

	cin.rdbuf(cinbuf);
	system("pause");

#endif

	return 0;
}