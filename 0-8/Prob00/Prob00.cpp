#include <iostream>
#include "bintree_eda.h"
using namespace std;

bintree<char> leerArbol(istream& sin) {
	char raiz;
	sin >> raiz;

	if (raiz == '.') return bintree<char>();

	else {
		bintree<char> iz = leerArbol(sin);
		bintree<char> dr = leerArbol(sin);
		return bintree<char>(iz, raiz, dr);
	}

}

int main() {
	int nCasos;

	cin >> nCasos;

	for (int i = 0; i < nCasos; i++) {
		bintree<char> ar = leerArbol(cin);
		cout << ar.calculaAltura() << endl;
	}
	return 0;
}

