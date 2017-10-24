// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema mediante la idea recursiva que sigue:

palindromo(i, j) = tamaño del mayor palídromo posible en el mensaje formado con lso patitos desde el
				de la posición i hasta el de la posición j

palindromo(i, j) =>		Si msg[i] == msg[j]	=>		2 + palindromo(i+1, j-1)
						sino						max(palindromo(i+1, j), palindromo(i, j-1))
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include "IndexPQ.h"
#include "Matriz.h"

using namespace std;

const int INF = 1000000000;

void printMatriz(Matriz<int> m){
	for (int i = 0; i < m.numfils(); i++){
		for (int j = 0; j < m.numcols(); j++)
			cout << m[i][j] << " ";
		cout << endl;
	}

}

/*
Aplicando la idea recursiva resolvemos el problema mediante el uso de una matriz de NxN siendo N el 
número de patitos, en la cual guardamos para cada posición de caracteres i y j el valor máximo del 
palidromo formado hasta el momento desde un patito i hasta el patito j.
Luego para obtener la solución recorremos la matriz de forma inversa a como a hemos formado teniendo en
cuenta que solo introducimos una letra en el palindromo cuando msg[i]==msg[j], dicha letra la introducimos
en ambos lados de un string del tamaño del palindromo obtenido en la solución del problema, dicho string 
lo recorremos mediante 2 cursores.

Coste en tiempo: es del O(N^2) siendo N el número de patitos.
Coste en espacio: el espacio requerido es de N^2 elementos enteros para la matriz y de M caracteres para
el palíndromo solución, por tanto el espacio requerido es N^2*4 + M bytes en espacio.
*/
string palindromo(string msg) {

	int tam = msg.size(), i ,j;
	Matriz<int> pal(tam, tam, 0);

	for (i = tam-1; i >= 0; i--){
		pal[i][i] = 1;
		for (j = i+1; j < tam; j++){
			if (msg[i] == msg[j])
				pal[i][j] = pal[i + 1][j - 1] + 2;
			else
				pal[i][j] = max(pal[i + 1][j], pal[i][j - 1]);
		}
	}

	string palindromo(pal[0][tam-1], ' ');
	i = 0; 
	j = tam-1;
	int n = 1 + ((pal[0][tam - 1] - 1) / 2), act, k=0, izq=0, der= pal[0][tam - 1]-1;
	
	while (k < n) {
		act = pal[i][j];
		if (msg[i] == msg[j]) {
			palindromo[izq] = palindromo[der] = msg[i];
			++k; ++izq; --der; ++i; --j;
		}
		else if(act == pal[i + 1][j])
			++i;
		else 
			--j;
	}
	
	return palindromo;
}

bool resuelveCaso() {
	string msg;

	cin >> msg;

	if (!cin)
		return false;

	cout << palindromo(msg) << endl;

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}