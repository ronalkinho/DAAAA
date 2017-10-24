// Jose Antonio Bernal Pérez 3º E TAIS 
// Grado de Ingenieria del Software
// TAIS32

#include <fstream>
#include <iostream>
#include <string>

int equilibrado(std::string arbol, int& position)
{
	position++;
	if (arbol[position - 1] == '.') return 0;
	int alturaIzq = equilibrado(arbol, position);
	int alturaDer = equilibrado(arbol, position);
	if (alturaIzq != -1 && alturaDer != -1 && abs(alturaIzq - alturaDer) <= 1)
	{
		if (alturaIzq >= alturaDer) return alturaIzq+1;
		else return alturaDer+1;
	}
	else
		return -1;
}

void resuelveCaso(){
	std::string arbol;
	getline(std::cin, arbol);
	int balance = 0;
	int position = 0;
	if (arbol.size() > 1)
		balance = equilibrado(arbol, position);
	if (balance != -1) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("Test.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	std::cin.get();
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}