// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema mediante el uso de una cola de prioridad, la cual se encarga de guardar
los restaurantes ordenados por el inicio de su rango de influencia, ya que lo que guardamos en 
la cola es un tipo t_restaurante que dice donde empieza y donde acaba el influjo del mismo.
El algoritmo cuenta con 2 índices: "sig" que marca el punto actual de la calle hasta el cual tenemos
cubierto por un restaurante y "ant" que marca el final del anterior punto de cobertura de la calle.
Entonces vamos sacando locales y comparando que su inicio no sea posterior al sig actual, lo que 
significaría que estamos dejando un hueco.
Si se cumple esta condición ahora comprobamos si el inicio actual es anterior a ant, lo que significaría
que si además abarca más calle con su fin hay que cambiar el local anterior con este nuevo, actualizando
fin y no incrementando el contador de locales necesarios.
Si por el contrario su inicio es posterior al ant entonces es que simplemente añadimos este local a
los que ya había antes (de superarse la marca de fin, claro), entonces actualizamos ant, sig e 
incrementamos el número de locales necesarios.
Se realizará este bucle hasta que acabemos con todos los restaurantes posibles o ya hayamos abarcado
toda la calle.
En el caso de el número de restaurantes sea 0 se devolverá siempre -1, y si solo hay una unidad de tamaño
de la calle (habiendo al menos un restaurante) entonces el número de locales necesarios solo es 1.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

struct t_restaurante{
	int ini;
	int fin;
};

bool operator <(t_restaurante a, t_restaurante b){
	return a.ini < b.ini;
}

/*
Coste: es de O(N log N) siendo N el número de locales
*/
bool resuelveCaso() {
	int calle, restaurantes;
	cin >> calle >> restaurantes;

	if (!cin)
		return false;

	int locales = 0, loc, rad, ant = 0, sig = 1;
	t_restaurante rest;
	PriorityQueue<t_restaurante> listaRest(restaurantes);
	
	for (int i = 0; i < restaurantes; ++i){
		cin >> loc >> rad;
		if (loc - rad < 1)
			rest.ini = 1;
		else
			rest.ini = loc - rad;
		rest.fin = loc + rad;
		listaRest.push(rest);
	}
	
	if (restaurantes > 0){
		if (calle > 1){
			while (!listaRest.empty() && sig < calle) {
				rest = listaRest.top();
				listaRest.pop();
				if (rest.ini <= sig){
					if (rest.ini <= ant){
						if (rest.fin > sig)
							sig = rest.fin;
					}
					else if (rest.fin > sig){
						ant = sig;
						sig = rest.fin;
						locales++;
					}
				}
			}
		}
		else
			locales = 1;
	} 

	if (sig < calle)
		cout << -1 << endl;
	else
		cout << restaurantes - locales << endl;
		
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
