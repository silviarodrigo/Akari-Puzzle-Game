//Silvia Rodrigo Cañete 

#pragma once

#ifndef ModuloTablero_h
#define ModuloTablero_h
#include"ModuloCasilla.h"
#include"ModuloPosicion.h"
#include<iostream>

//colores para letras
#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define WHITE   "\x1B[37m"
#define RESET   "\x1b[0m"
//colores para fondos
#define BG_RED     "\x1B[41m"
#define BG_YELLOW  "\x1B[43m"
#define BG_BLUE    "\x1B[44m"
#define BG_WHITE   "\x1B[47m"

using namespace std;

const int MAX_FILS = 10;
const int MAX_COLS = 10;

using tArrayCasillas = tCasilla[MAX_FILS][MAX_COLS];

struct tTablero{
	int nFils, nCols;
	tArrayCasillas datos;
};

istream& operator>>(istream& in, tTablero& tablero);
ostream& operator<<(ostream& out, tTablero& tablero);

tCasilla casillaEnPos(tTablero const& tablero, tPos pos);
void cambiaCasilla(tTablero& tablero, tPos pos, tCasilla laCasilla);

//FUNCIONES AÑADIDAS EN VERSIÓN 2
ostream& operator<<(ofstream& archivo, const tTablero& tablero);

#endif // !ModuloTablero_h

