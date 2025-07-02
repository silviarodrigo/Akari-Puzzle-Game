//Silvia Rodrigo Cañete

#include"ModuloTablero.h"
#include"ModuloCasilla.h"
#include"ModuloJuego.h"
#include"ModuloPosicion.h"
#include"ModuloPartida.h"
#include"ModuloListaPartidas.h"
#include"ModuloListaPosiciones.h"
#include<iostream>
#include<fstream>
#include<iomanip>

//comprobamos que no hay memory leaks
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>


using namespace std;

void partida() {
	tListaPartidas listaPartidas;
	cout << "Dame el nombre del fichero que contiene el tablero: ";
	string fich_nombre;
	cin >> fich_nombre;
	ifstream archivo;
	archivo.open(fich_nombre);
	if (!archivo.is_open()) {
		cout << "Por favor introduzca el nombre de un fichero valido.\n";
	}
	else {
		//guardamos los datos de la lista de Partidas
		archivo >> listaPartidas;
		archivo.close();
		//comenzamos a jugar
		cout << "\nDame el nivel a jugar (>0): ";
		int nivel;
		cin >> nivel;

		tPartida* p;
		int nElem = dameNumElem(listaPartidas);
		int pos = 0;

		p = dameElem(listaPartidas, nElem - 1);
		//Si el nivel es mas grande que los de la lista cogemos el ultimo nivel
		if (*p < nivel) {
			nivel = p->nivel;
			pos = nElem - 1;
		}
		else {
			pos = buscaPos(listaPartidas, nivel);
			//si el nivel no existe en la lista busca el siguiente nivel
			while (pos == -1 && nivel < *p) {
				nivel++;
				pos = buscaPos(listaPartidas, nivel);
			}
		}
		//Ponemos el contador de juego a 0 y jugamos el nivel elegido
		int nIt = 0;
		p = dameElem(listaPartidas, pos);
		bool abandonado = juega(p, nIt);
		//Si ganamos el nivel lo borramos de la lista de partidas
		if (!abandonado) {
			eliminarPartida(listaPartidas, *p);
		}
		p = nullptr;

		//Guardamos las partidas en un fichero de salida
		cout << "Dame el nombre del archivo para guardar: ";
		cin >> fich_nombre;
		ofstream archivo;
		archivo.open(fich_nombre);
		archivo << listaPartidas;
		archivo.close();

		//Liberamos la memoria dinamica usada
		destruyeListaPartidas(listaPartidas);
	}
}

int main() {
	//ejectuamos el juego
	partida();
	//comprobamos que no hay memory leaks
	_CrtDumpMemoryLeaks();
	return 0;
}