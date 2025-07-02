//Silvia Rodrigo Cañete

#include"ModuloJuego.h"
#include"ModuloTablero.h"
#include"ModuloPosicion.h"
#include"ModuloCasilla.h"
#include<iostream>

using namespace std;

//Si la posicion es correcta (previamente comprobado en el main) trabajamos con ella
void ejecutarPos(tTablero& tablero, tPos pos) {
	bool iluminar;
	tCasilla c;
	tCasilla aux;
	c = casillaEnPos(tablero, pos);
	//si la posicion elegida no tiene bombilla ni esta iluminada hay que poner una bombilla e iluminar las casillas a las que afecta
	if (c.tipo == LIBRE && c.numBombillas == 0) {
		iluminar = true;
		aux.tipo = BOMBILLA;
		cambiaCasilla(tablero, pos, aux);
		cambiarIluminacion(tablero, pos, iluminar);
	}
	//si la posicion elegida ya tiene una bombilla hay que quitarla y desluminar las casillas a las que afecta
	else if (c.tipo == BOMBILLA) {
		iluminar = false;
		aux.tipo = LIBRE;
		aux.numBombillas = 0;
		cambiaCasilla(tablero, pos, aux);
		cambiarIluminacion(tablero, pos, iluminar);
	}
	//En caso de que la posicion ya este iluminada o sea una pared no hay que editar el tablero
}

//Funcion que llama a todas las direcciones que rodean a una posicion para iluminarlas o desiluminarlas
void cambiarIluminacion(tTablero& tablero, tPos pos, bool iluminar) {
	cambiarIluminacionDir(tablero, pos, NORTE, iluminar);
	cambiarIluminacionDir(tablero, pos, SUR, iluminar);
	cambiarIluminacionDir(tablero, pos, ESTE, iluminar);
	cambiarIluminacionDir(tablero, pos, OESTE, iluminar);
}
//Cambiamos la iluminacion de las casillas afectadas por la posicion en una direccion determinada
void cambiarIluminacionDir(tTablero& tablero, tPos pos, tDir dir, bool iluminar) {
	tCasilla c;
	c = casillaEnPos(tablero, pos);
	avanzarPosDir(pos, dir);
	//mientras la posicion exista y no sea una pared seguimos iluminando/desiluminando la fila/columna
	while (PosCorrecta(pos, tablero.nFils, tablero.nCols) && c.tipo != PARED) {
		c = casillaEnPos(tablero, pos);
		if (iluminar) {
			iluminarCasilla(c);
		}
		else {
			desiluminarCasilla(c);
		}
		tablero.datos[pos.i][pos.j] = c;
		avanzarPosDir(pos, dir);
	}
}

//comprueba si la persona ha ganado, es decir si cumple todos los requisitos del juego
bool hasGanado(const tTablero& tablero) {
	tPos p;
	bool hasGanado = true;
	p.i = 0;
	while (p.i < tablero.nFils && hasGanado) {
		p.j = 0;
		while (p.j < tablero.nCols && hasGanado) {
			if (!seCumpleRestriccionFin(tablero, p)) {
				hasGanado = false;
			}
			p.j++;
		}
		p.i++;
	}
	return hasGanado;
}
//comprueba que todas las casillas cumplen los requisitos
bool seCumpleRestriccionFin(const tTablero& tablero, tPos pos) {
	//si todas las libres estan iluminadas
	if (tablero.datos[pos.i][pos.j].tipo == LIBRE) {
		if (tablero.datos[pos.i][pos.j].numBombillas > 0) {
			return true;
		}
		else return false;
	}
	//si todas las paredes con numero tienen las bombillas necesarias alrededor
	else if (tablero.datos[pos.i][pos.j].tipo == PARED && tablero.datos[pos.i][pos.j].numBombillas > -1) {
		int numB = numBombillasVecinas(tablero, pos);
		if (numB == tablero.datos[pos.i][pos.j].numBombillas) {
			return true;
		}
		else return false;
	}
	//si no es libre o pared con numero, es decir es bombilla o pared normal, siempre cumplira los requisitos porque no hay ninguno impuesto
	else return true;
}
//comprueba cuantas bombillas rodean a una determinada posicion
int numBombillasVecinas(const tTablero& tablero, tPos pos) {
	tCasilla c;
	int cont = 0;
	for (int i = 0; i < 4; i++) {
		pos.i += incF[i];
		pos.j += incC[i];
		c = casillaEnPos(tablero, pos);
		if (PosCorrecta(pos, tablero.nFils, tablero.nCols) && c.tipo == BOMBILLA) {
			cont++;
		}
	}
	return cont;
}
//Resetea el tablero manteniendo las paredes pero cambiando el resto de casillas a casillas libres no iluminadas
void resetearJuego(tTablero& tablero) {
	for (int i = 0; i < tablero.nFils; i++) {
		for (int j = 0; j < tablero.nCols; j++) {
			if (tablero.datos[i][j].tipo == LIBRE) {
				tablero.datos[i][j].numBombillas = 0;
			}
			else if (tablero.datos[i][j].tipo == BOMBILLA) {
				tablero.datos[i][j].tipo = LIBRE;
				tablero.datos[i][j].numBombillas = 0;
			}
		}
	}
	cout << "Se ha reseteado el juego";
}


