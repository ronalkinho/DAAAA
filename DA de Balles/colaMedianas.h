#include <iostream>
#include "ColaPrio.h" 

using namespace std;

//template <class T, bool(*mayor)(const T &, const T &), bool(*menor)(const T &, const T &)>


bool mayor(const int& n1, const int& n2){
	return n1 > n2;
}
bool menor(const int &n1, const int& n2){
	return n1 < n2;
}

class ColaMedianas {
public:
	ColaMedianas(){
		m = -1;
		colaVacia = true;

		//menores = ColaPrio < int, mayor >();
		//mayores = ColaPrio <int, menor >();
	}

	void inserta(int n){
		if (colaVacia){ // si no hay ningun elemeno la mediana es el numero directamente
			m = n;
			colaVacia = false;
		}
		else{
			if (n < m){
				menores.inserta(n);
			}
			else if (n > m){
				mayores.inserta(n);
			}
		else{
				if (menores.numElem() > mayores.numElem())
					mayores.inserta(n);
				else
					menores.inserta(n);
			}
		}

		int aux = mayores.numElem() - menores.numElem();
		if (aux > 1){
			menores.inserta(m);
			m = mayores.primero();
			mayores.quitaPrim();
		}
		else if (aux < 0){
			mayores.inserta(m);
			m = menores.primero();
			menores.quitaPrim();
		}

	}

	int mediana(){
		return m;
	}

	void quitaMediana(){
		if (menores.numElem() >= mayores.numElem()){
			m = menores.primero();
			menores.quitaPrim();
		}
		else{
			m = mayores.primero();
			mayores.quitaPrim();
		}
	}

private:
	int m;
	bool colaVacia;
	ColaPrio<int, mayor> menores; //de máximos
	ColaPrio<int, menor> mayores; //de minimos
};