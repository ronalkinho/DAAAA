// Grupo 18, Cristian V�zquez Oll� y Julio �lvarez Mart�n

/*
Resolvemos el problema empleando 2 colas de prioridad, una de m�ximos y otra de m�nimos. Lo que haremos ser�
ir introduciendo los valores en la cola correspondiente de tal manera que los valores centrales de la serie
siempre queden en el top de ambas colas, en el caso de que sea par se coger�n ambos y cuando sea impar la serie
se coger� el de la cola de m�ximos (por tanto esta cola podr� tener el mismo n�mero de elementos o uno m�s que la
de m�nimos)
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

using namespace std;

/*
Esta funci�n comprobar� a que cola corresponde introducir el n�mero actual seg�n el estado de las mismas, es decir,
si estan vac�as o la relaci�n entre el n�mero actual con los elementos que est�n en el top de las colas.
Una vez introducido en la cola correspondiente se comprueba que las colas est�n equilibradas para evitar que una de 
ellas tenga mas de 1 elemento de diferencia con la otra (solo puede tener uno m�s la de m�ximos) y en el caso de que
no se cumpla se equilibran.

Coste: lineal en el n�mero de elementos de la cola, por su recorrido uno a uno, y logar�tmica en la 
ordenaci�n del elemento al introducirlo o sacarlo de la cola, por tanto tiene un coste de N log(N) 
siendo N el n�mero de elementos de caso de prueba
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
