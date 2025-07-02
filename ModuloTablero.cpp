//Silvia Rodrigo Cañete 

#include"ModuloTablero.h"
#include"ModuloCasilla.h"
#include"ModuloPosicion.h"
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

//CARGA DE TABLERO
//Editado porque el tablero ya está abierto (versión 2)
istream& operator>>(istream& archivo, tTablero& tablero) {
	archivo >> tablero.nFils >> tablero.nCols;
	char casilla = ' ';
	for (int i = 0; i < tablero.nFils; i++) {
		for (int j = 0; j < tablero.nCols; j++) {
			archivo >> casilla;
			if (casilla == '.') {
				tablero.datos[i][j].tipo = LIBRE;
				tablero.datos[i][j].numBombillas = 0;
			}
			else if (casilla == 'X') {
				tablero.datos[i][j].tipo = PARED;
				tablero.datos[i][j].numBombillas = -1;
			}
			else {
				int num = casilla - 48;
				tablero.datos[i][j].tipo = PARED;
				tablero.datos[i][j].numBombillas = num;
			}

		}
	}
	return archivo;

}

//IMPRIMIMOS TABLERO
ostream& operator<<(ostream& out, tTablero& tablero) {
	out << "	 |";
	for (int j = 0; j < tablero.nCols; j++) {
		out << " " << BLUE << j << RESET << " |";
	}
	out << "\n" << "	" << "-+";
	for (int j = 0; j < tablero.nCols; j++) {
		out << setfill('-') << setw(4) << "+";
	}
	out << "\n";
	for (int i = 0; i < tablero.nFils; i++) {
		out << "	";
		out << BLUE << i << RESET << "|";
		for (int j = 0; j < tablero.nCols; j++) {
			if (tablero.datos[i][j].tipo == LIBRE) {
				if (tablero.datos[i][j].numBombillas == 0) {
					out << BG_WHITE << "   " << RESET << "|";
				}
				else {
					out << BG_YELLOW << "   " << RESET << "|";
				}
			}
			else if (tablero.datos[i][j].tipo == PARED) {
				if (tablero.datos[i][j].numBombillas == -1) {
					out << setfill(' ') << setw(4) << "|";
				}
				else {
					out << setfill(' ') << setw(3) << tablero.datos[i][j].numBombillas << "|";
				}
			}
			else {
				out << BG_YELLOW << "  " << RED << "*" << RESET << "|";
			}
		}
		out << "\n" << "	" << "-+";
		for (int j = 0; j < tablero.nCols; j++) {
			out << setfill('-') << setw(4) << "+";
		}
		out << "\n";
	}
	return out;
}

//imprimios el tablero en el archivo de texto (version 2)
ostream& operator<<(ofstream& archivo, const tTablero& tablero) {
	archivo << tablero.nFils <<" " << tablero.nCols<<"\n";
	for (int i = 0; i < tablero.nFils; i++) {
		for (int j = 0; j < tablero.nCols; j++) {
			if (tablero.datos[i][j].tipo == LIBRE || tablero.datos[i][j].tipo == BOMBILLA) {
				archivo << '.';
			}
			else if (tablero.datos[i][j].tipo == PARED && tablero.datos[i][j].numBombillas == -1) {
				archivo << 'X';
			}
			else {
				archivo << tablero.datos[i][j].numBombillas;
			}
		}
		archivo << "\n";
	}
	return archivo;
}

//separamos en un struct la posicion del tablero con la que queremos trabajar
tCasilla casillaEnPos(tTablero const& tablero, tPos pos) {
	return tablero.datos[pos.i][pos.j];
}
//actualizamos los datos del tablero despues de modificar una posicion
void cambiaCasilla(tTablero& tablero, tPos pos, tCasilla laCasilla) {
	tablero.datos[pos.i][pos.j] = laCasilla;
}
