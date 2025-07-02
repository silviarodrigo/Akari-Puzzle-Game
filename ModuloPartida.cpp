//Silvia Rodrigo Cañete 

#include"ModuloPartida.h"
#include"ModuloTablero.h"
#include"ModuloListaPosiciones.h"
#include"ModuloListaPartidas.h"
#include"ModuloCasilla.h"
#include"ModuloJuego.h"
#include"ModuloPosicion.h"
#include<iostream>
#include<fstream>

using namespace std;

//CARGAMOS LA PARTIDA
ifstream& operator>>(ifstream& archivo, tPartida*& partida) {
	iniciaPartida(*partida);
	string level;
	archivo >> level >> partida->nivel;
	archivo >> partida->tablero;
	archivo >> partida->listaBombillas;
	return archivo;
}
//IMPRIMIMOS LA PARTIDA
ofstream& operator<<(ofstream& archivo, const tPartida& partida) {
	archivo << "LEVEL " << partida.nivel << "\n";
	archivo << partida.tablero;
	archivo << partida.listaBombillas;
	return archivo;
}

//creada la lista de partidas inicializamos todas las partidas 
void iniciaPartida(tPartida& partida) {
	partida.nivel = 0;
	iniciaListaPosiciones(partida.listaBombillas);
}

//Eliminamos una partida definitivamente liberando su memoria dinamica
void destruyePartida(tPartida*& partida){
	partida->nivel = 0;
	destruyeListaPosiciones(partida->listaBombillas);
	delete partida;
}

//Compara si el nivel de una partida es menor/mayor qye el de otra o que uno dado 
bool operator<(const tPartida& partida, int nivel) {
	return partida.nivel < nivel;
}

bool operator<(const tPartida& partida1, const tPartida& partida2) {
	return partida1.nivel < partida2.nivel;
}
//AÑADIDA
bool operator<(int nivel, const tPartida& partida) {
	return nivel < partida.nivel;
}
//Fin de comparaciones

bool juega(tPartida*& partida, int& nIt) {
	//ponemos todas las bombillas proporcionadas por la lista (puestas ahi por partidas anteriores que se han abandonado o como predeterminadas)
	tPos p;
	int cont = dameNumElem(partida->listaBombillas);
	for (int i = 0; i < cont; i++) {
		p = dameElem(partida->listaBombillas, i);
		ejecutarPos(partida->tablero, p);
	}

	tPos pos;
	nIt = 1;
	cout << partida->tablero;
	pedirPos(pos);
	
	while (!hasGanado(partida->tablero) && !esPosQuit(pos)) {
		//comprobamos que no queremos resetear el tablero
		if (esPosReset(pos)) {
			resetearJuego(partida->tablero);
			cout << " en el movimiento " << nIt << ".\n\n";
			destruyeListaPosiciones(partida->listaBombillas);
			iniciaListaPosiciones(partida->listaBombillas);
			cout << partida->tablero << "\n";
			pedirPos(pos);
			nIt++;
		}
		//comprobamos que la posicion existe en el tablero
		else if (PosCorrecta(pos, partida->tablero.nFils, partida->tablero.nCols)) {
			insertar(partida->listaBombillas, pos);
			ejecutarPos(partida->tablero, pos);
			//escribimos que hemos hecho en el movimiento
			tCasilla c;
			c = casillaEnPos(partida->tablero, pos);
			if (c.tipo == LIBRE && c.numBombillas == 0) {
				cout << "Se ha quitado la bombilla";
			}
			else if (c.tipo == BOMBILLA) {
				cout << "Se ha puesto una bombilla";
			}
			else {
				cout << "No se ha puesto bombilla";
			}
			cout << " en el movimiento " << nIt << ".\n\n";
			//imprimios el tablero
			cout << partida->tablero << "\n";
			if (!hasGanado(partida->tablero)) {
				pedirPos(pos);
				nIt++;
			}
		}
		//en caso de que no exista pedimos una posicion nueva
		else {
			cout << "Introduzca una posicion correcta.\n";
			pedirPos(pos);
		}
	}
	//comprobamos si se ha ganado
	if (hasGanado(partida->tablero)) {
		cout << "Has ganado en "<<nIt<<" movimientos. :-)\n\n";
		return false;
	}
	//si no se ha ganado, se ha tenido que abandonar el juego (en el movimiento x)
	else {
		cout << " en el movimiento " << nIt << " Adeus! Adeus!" << "\n\n";
		cout << partida->tablero << "\n";
		return true;
	}
}