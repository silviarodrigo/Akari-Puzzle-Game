//Silvia Rodrigo Cañete 

#include"ModuloListaPosiciones.h"
#include"ModuloPosicion.h"
#include<iostream>
#include<fstream>

using namespace std;

//CARGAMOS LA LISTA
ifstream& operator>>(ifstream& archivo, tListaPosiciones& lp) {
	int numpos;
	tPos aux;
	archivo >> numpos;
	for (int i = 0; i < numpos; i++) {
		archivo >> aux.i >> aux.j;
		insertar(lp, aux);
	}
	return archivo;
}

//IMPRIMIMOS LA LISTA
ofstream& operator<<(ofstream& archivo, const tListaPosiciones& lp) {
	archivo << lp.cont << "\n";
	for (int i = 0; i < lp.cont; i++) {
		archivo << lp.arrayPos[i].i << " " << lp.arrayPos[i].j << "\n";
	}
	return archivo;
}

//Creada una nueva partida inicializamos sus lista a 0, y el array de dimension DIM
void iniciaListaPosiciones(tListaPosiciones& lp) {
	lp.cont = 0;
	lp.size = DIM;
	lp.arrayPos = new tPos[lp.size];
}

//Elimina la memoria utilizada para crear la lista, una vez queremos borrar la partida
void destruyeListaPosiciones(tListaPosiciones& lp) {
	delete[] lp.arrayPos;
	lp.arrayPos = nullptr;
	lp.size = 0;
	lp.cont = 0;
}

//Añadimos una nueva posicion a la lista
void insertar(tListaPosiciones& lp, const tPos& pos) {
	if (lp.cont < lp.size) {
		lp.arrayPos[lp.cont] = pos;
		lp.cont++;
	}
	else {
		//Si la posicion no cabe en el array lo agrandamos
		tPos* aux = nullptr;
		int tamano = 2 * lp.size;
		aux = new tPos[tamano];
		for (int i = 0; i < lp.size; i++) {
			aux[i] = lp.arrayPos[i];
		}
		delete[] lp.arrayPos;
		lp.arrayPos = aux;
		lp.size = tamano;
		aux = nullptr;
		lp.arrayPos[lp.cont] = pos;
		lp.cont++;
	}
}

//Devuleve el contador de la lista
int dameNumElem(const tListaPosiciones& lp) {
	return lp.cont;
}
//Devuelve el elemento de la lista en la posicion indicada
tPos dameElem(const tListaPosiciones& lp, int i) {
	return lp.arrayPos[i];
}