//Silvia Rodrigo Cañete 
#pragma once

#ifndef ModuloListaPosiciones_h
#define ModuloListaPosiciones_h

#include"ModuloPosicion.h"
#include<iostream>
#include<fstream>

using namespace std;

const int DIM = 2;
struct tListaPosiciones {
	int cont;
	int size;
	tPos* arrayPos;
};

ifstream& operator>>(ifstream& archivo, tListaPosiciones& lp);
ofstream& operator<<(ofstream& archivo, const tListaPosiciones& lp);

void iniciaListaPosiciones(tListaPosiciones& lp);
void destruyeListaPosiciones(tListaPosiciones& lp);
void insertar(tListaPosiciones& lp, const tPos& pos);
int dameNumElem(const tListaPosiciones& lp);
tPos dameElem(const tListaPosiciones& lp, int i);


#endif // !ModuloListaPosiciones.h