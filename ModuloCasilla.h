//Silvia Rodrigo Cañete 

#pragma once

#ifndef ModuloCasilla_h
#define ModuloCasilla_h
#include<iostream>
using namespace std;

enum tTipo {
	PARED,
	BOMBILLA,
	LIBRE
};

struct tCasilla {
	tTipo tipo;
	int numBombillas;
};

void iluminarCasilla(tCasilla& casilla);
void desiluminarCasilla(tCasilla& casilla);

#endif // !ModuloCasilla_h
