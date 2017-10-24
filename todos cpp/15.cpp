// Jose Antonio Bernal Pérez TAIS32 3ºE
// Ingenieria del Software

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

#include "Grafo.h"

class CC{
private:
	vector<bool> marked;
	vector<int> id;
	int count;

	void dfs(const Grafo& g, int v){
		marked[v] = true;
		id[count]++;
		for (int w : g.adj(v)){
			if (!marked[w])
				dfs(g, w);
		}
	}
public:
	CC(const Grafo& g) : marked(g.V(), false), id(g.V()), count(0){
		for (int v = 0; v < g.V(); v++)
		{
			if (!marked[v])
			{
				dfs(g, v);
				count++;
			}
		}
	}

	int getCount(){ return count; }
	int getId(int v){ return id[v]; }
	int max(){
		int max = 0;
		for (int i = 0; i <= count; i++)
		{
			if (id[i] > max)
				max = id[i];
		}
		return max;
	}
};

// resuelve un caso de prueba
void resuelveCaso() {
	int filas, columnas;
	cin >> filas;
	cin >> columnas;
	Grafo grafo(filas*columnas);
	vector<bool> manchado(filas*columnas, false);
	char petr;
	for (int i = 0; i < filas*columnas; i++)
	{
		cin.get(petr);
		if (petr == '\n')
			cin.get(petr);
		if (petr == '#'){
			manchado[i] = true;
			if (i > 0 && i % columnas != 0 && manchado[i - 1] == true)
				grafo.ponArista(i, i - 1);
			if (i < filas*columnas - 1 && i % columnas != columnas - 1 && manchado[i + 1] == true)
				grafo.ponArista(i, i + 1);
			if (i - columnas >= 0 && manchado[i - columnas] == true)
				grafo.ponArista(i, i - columnas);
			if (i + columnas < filas*columnas - 1 && manchado[i + columnas] == true)
				grafo.ponArista(i, i + columnas);
		}
	}
	CC sol(grafo);
	int imagenes;
	cin >> imagenes;
	int solMax = sol.max();
	cout << solMax << '\n';
	for (int i = 0; i < imagenes; i++){
		int fila, columna;
		cin >> fila;
		cin >> columna;
		int pos = (fila-1)*columnas + columna-1;
		manchado[pos] = true;
		if (pos > 0 && pos % columnas != 0 && manchado[pos - 1] == true)
			grafo.ponArista(pos, pos - 1);
		if (pos < filas*columnas - 1 && pos % columnas != columnas - 1 && manchado[pos + 1] == true)
			grafo.ponArista(pos, pos + 1);
		if (pos - columnas >= 0 && manchado[pos - columnas] == true)
			grafo.ponArista(pos, pos - columnas);
		if (pos + columnas < filas*columnas - 1 && manchado[pos + columnas] == true)
			grafo.ponArista(pos, pos + columnas);
		CC sol(grafo);
		int nuevaSol = sol.max();
		if (nuevaSol > solMax)
			solMax = nuevaSol;
		cout << solMax;
	}
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (!cin.eof())
		resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}