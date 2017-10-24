// Grupo 18, Cristian Vázquez Ollé y Julio Álvarez Martín

/*
Resolvemos el problema empleando 2 colas de prioridad, una de máximos y otra de mínimos. Lo que haremos será
ir introduciendo los valores en la cola correspondiente de tal manera que los valores centrales de la serie
siempre queden en el top de ambas colas, en el caso de que sea par se cogerán ambos y cuando sea impar la serie
se cogerá el de la cola de máximos (por tanto esta cola podrá tener el mismo número de elementos o uno más que la
de mínimos)
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

/*
Esta función comprobará a que cola corresponde introducir el número actual según el estado de las mismas, es decir,
si estan vacías o la relación entre el número actual con los elementos que están en el top de las colas.
Una vez introducido en la cola correspondiente se comprueba que las colas estén equilibradas para evitar que una de 
ellas tenga mas de 1 elemento de diferencia con la otra (solo puede tener uno más la de máximos) y en el caso de que
no se cumpla se equilibran.

Coste: lineal en el número de elementos de la cola, por su recorrido uno a uno, y logarítmica en la 
ordenación del elemento al introducirlo o sacarlo de la cola, por tanto tiene un coste de N log(N) 
siendo N el número de elementos de caso de prueba
*/
void resuelveCaso(int n) {
	PriorityQueue<int,std::greater<int>> pI(n);
	PriorityQueue<int> pD(n);
	int num;
	for (int i=0; i < n; ++i){
		std::cin >> num;
		if (pI.empty())
			pI.push(num);
		else if (pD.empty() && num>pI.top())
			pD.push(num);
		else if (num <= pI.top())
			pI.push(num);
		else if (num >= pD.top())
			pD.push(num);
		else
			pI.push(num);

		if (pI.size() == pD.size() + 2){
			num = pI.top();
			pI.pop();
			pD.push(num);
		}
		else if (pD.size() == pI.size() + 1){
			num = pD.top();
			pD.pop();
			pI.push(num);
		}

		if ((i+1)%2 == 0)
			std::cout << pI.top() + pD.top() << " ";
		else
			std::cout << pI.top()*2 << " ";

	}
	std::cout << endl;
}

int main() {
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int num;
	PriorityQueue<int> p;
	std::cin >> num;
	while (num != 0){
		resuelveCaso(num);
		std::cin >> num;
	}
	
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	return 0;
}
