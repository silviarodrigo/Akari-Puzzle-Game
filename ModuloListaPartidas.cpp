//Silvia Rodrigo Cañete 

#include"ModuloListaPartidas.h"
#include"ModuloPartida.h"
#include<iostream>


using namespace std;

//CARGAMOS LA LISTA
ifstream& operator>>(ifstream& archivo, tListaPartidas& listaPartidas) {
	int numPartidas;
	archivo >> numPartidas;
	for (int i = 0; i < numPartidas; i++) {
		listaPartidas.datos[i] = new tPartida;
		archivo >> listaPartidas.datos[i];
		listaPartidas.nElem++;
		insertarOrd(listaPartidas, *listaPartidas.datos[i]);
	}
	return archivo;
}

//IMPRIMIMOS LA LISTA
ofstream& operator<<(ofstream& archivo, const tListaPartidas& listaPartidas) {
	archivo << listaPartidas.nElem << "\n";
	for (int i = 0; i < listaPartidas.nElem; i++) {
		archivo << *listaPartidas.datos[i];
	}
	return archivo;
}



//Ordenamos los elementos de la lista a medida que los vamos recibiendo (se ordenaran por nivel)
void intercambiar(tPartida*& x, tPartida*& y) {
	tPartida* aux = x;
	x = y;
	y = aux;
}

void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida) {
	if (listaPartidas.nElem == 1);
	else {
		int pos2 = 0;
		while (pos2 < listaPartidas.nElem && (*listaPartidas.datos[listaPartidas.nElem - 1] < *listaPartidas.datos[pos2])) {
			intercambiar(listaPartidas.datos[pos2], listaPartidas.datos[listaPartidas.nElem - 1]);
			pos2++;
		}
	}
}

//Liberamos la memoria dinamica utilizada (borramos las partidas creadas y ponemos el contador a 0)
void destruyeListaPartidas(tListaPartidas& listaPartidas) {
	for (int i = 0; i < listaPartidas.nElem; i++) {
		destruyePartida(listaPartidas.datos[i]);
		listaPartidas.datos[i] = nullptr;
	}
	listaPartidas.nElem = 0;
}

//Borra una unica partida de la lista (despues de ganarla)
void eliminarPartida(tListaPartidas& listaPartidas, const tPartida& partida) {
	int pos = buscaPos(listaPartidas, partida.nivel);
	destruyePartida(listaPartidas.datos[pos]);
	listaPartidas.datos[pos] = nullptr;
	for (int i = pos; i < listaPartidas.nElem - 1; i++) {
		listaPartidas.datos[i] = listaPartidas.datos[i + 1];
	}
	listaPartidas.datos[listaPartidas.nElem - 1] = nullptr;
	listaPartidas.nElem--;
}

//buscamos deonde esta una partida en la lista (dado el nivel, que sabemos que es unico)
int buscaPos(const tListaPartidas& listaPartidas, int nivel) {
	bool encontrado = false;
	int mitad, ini = 0, fin = listaPartidas.nElem;
	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2;
		if (listaPartidas.datos[mitad]->nivel == nivel) {
			encontrado = true;
		}
		else if (nivel < listaPartidas.datos[mitad]->nivel) {
			fin = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}
	}
	if (encontrado) {
		return mitad;
	}
	else return -1;
}

//dada la lista de devuelve el puntero que se encuentra en la posicion elegida
tPartida* dameElem(const tListaPartidas& listaPartidas, int pos) {
	if (pos < listaPartidas.nElem) {
		return listaPartidas.datos[pos];
	}
	else return NULL;
}

//devuelve el contador de la lista de partidas
int dameNumElem(const tListaPartidas& listaPartidas) {
	return listaPartidas.nElem;
}


