// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
#include <queue>
using namespace std;

struct Restaurante{
	int posicion;
	int radio;
	int id;

	Restaurante(){};
	Restaurante(int p, int r, int i) : posicion(p), radio(r), id(i){};
};

struct Intervalo{
	int a;
	int b;
	int puntCubiertos;
	
	Intervalo() : a(-1), b(-1), puntCubiertos(0){};
	Intervalo(int puntA, int puntB) : a(puntA), b(puntB), puntCubiertos(puntB - puntA){};
};

bool orden(Restaurante const& a, Restaurante const& b){ 
	if (a.radio > b.radio) return true;
	else if (a.radio == b.radio)
	{
		if (a.posicion < b.posicion) return true;
		else return false;
	}
	else return false;
}

// Coste R log R, donde R es el numero de restaurantes.
bool resuelveCaso() {
	int longitud, numRestaurantes;
	cin >> longitud;
	if (!cin) return false;
	cin >> numRestaurantes;
	vector<Restaurante> restaurantes(numRestaurantes);
	vector<Intervalo> influencias(numRestaurantes);
	vector<int> actualizados;
	for (int i = 0; i < numRestaurantes; i++)
	{
		int posicion, radio;
		cin >> posicion;
		cin >> radio;
		Restaurante r(posicion, radio, i);
		restaurantes[i] = r;
	}
	sort(restaurantes.begin(), restaurantes.end(), orden);
	int puntosCubiertos = 0;
	int prescindibles = 0;
	for (int i = 0; i < numRestaurantes; i++)
	{
		Restaurante actual = restaurantes[i];
		if (actualizados.empty())
		{
			int puntA, puntB;
			if (actual.posicion - actual.radio < 1) puntA = 1;
			else puntA = actual.posicion - actual.radio;
			if (actual.posicion + actual.radio > longitud) puntB = longitud;
			else puntB = actual.posicion + actual.radio;
			Intervalo intervalo(puntA, puntB);
			influencias[actual.id] = intervalo;
			puntosCubiertos = puntosCubiertos + intervalo.puntCubiertos;
			actualizados.push_back(actual.id); // Constante
		}
		else
		{
			vector<int>::const_iterator cit = actualizados.cbegin();
			bool libre = true;
			while (cit != actualizados.cend() && libre)
			{
				Intervalo i = influencias[*cit];
				if (actual.posicion >= i.a && actual.posicion <= i.b)
				{
					libre = false;
					prescindibles++;
				}
				else
					cit++;
			}
			if (libre)
			{
				int puntA, puntB;
				if (actual.posicion - actual.radio < 1) puntA = 1;
				else puntA = actual.posicion - actual.radio;
				if (actual.posicion + actual.radio > longitud) puntB = longitud;
				else puntB = actual.posicion + actual.radio;
				Intervalo intervalo(puntA, puntB);
				influencias[actual.id] = intervalo;
				puntosCubiertos = puntosCubiertos + intervalo.puntCubiertos;
				actualizados.push_back(actual.id); // Constante
			}
		}
	}
	if (puntosCubiertos >= longitud-1) cout << prescindibles << endl;
	else cout << -1 << endl;
	return true;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
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