//Silvia Rodrigo Cañete

#include"ModuloPosicion.h"
#include<iostream>

using namespace std;

//GUARDA LA POSICION
istream& operator>>(istream& in, tPos& pos) {
	int pos1, pos2;
	in >> pos1 >> pos2;
	pos.i = pos1;
	pos.j = pos2;
	return in;
}

//comprueba si la posicion metida existe en el tablero
bool PosCorrecta(const tPos& pos, int nFils, int nCols) {
	if (pos.i < 0 || pos.i >= nFils || pos.j >= nCols || pos.j < 0) {
		return false;
	}
	else return true;
}
//pide una posicion al jugador y la guarda
void pedirPos(tPos& pos) {
	cout << "Pos: ";
	cin >> pos;
}
//dada una direccion (norte, sur, este, oeste) avanza a la siguiente casilla en esa direccion
void avanzarPosDir(tPos& pos, const tDir& dir){
	if (dir == NORTE) {
		pos.i--;
	}
	else if (dir == SUR) {
		pos.i++;
	}
	else if (dir == ESTE) {
		pos.j++;
	}
	else pos.j--;
}
//comprueba si se quiere abandonar la partida
bool esPosQuit(const tPos& pos) {
	if (pos.i == -1 && pos.j == 0) {
		cout << "Se abandona el juego";
		return true;
	}
	else return false;
}
//comprueba si se quiere resetear el tablero
bool esPosReset(const tPos& pos) {
	if (pos.i == -1 && pos.j == -1) {
		return true;
	}
	else return false;
}
