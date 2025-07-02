//Silvia Rodrigo Cañete 
#pragma once

#ifndef ModuloPartida_h
#define ModuloPartida_h

#include"ModuloTablero.h"
#include"ModuloListaPosiciones.h"
#include"ModuloCasilla.h"
#include"ModuloJuego.h"
#include"ModuloPosicion.h"
#include<iostream>
#include<fstream>
using namespace std;

struct tPartida {
	tTablero tablero;
	tListaPosiciones listaBombillas;
	int nivel;
};

ifstream& operator>>(ifstream& archivo, tPartida*& partida);
ofstream& operator<<(ofstream& archivo, const tPartida& partida);

void iniciaPartida(tPartida& partida);
void destruyePartida(tPartida*& partida);
bool operator<(const tPartida& partida, int nivel);
//añadida
bool operator<(int nivel, const tPartida& partida);
//
bool operator<(const tPartida& partida1, const tPartida& partida2);
bool juega(tPartida*& partida, int& nIt);

#endif // !ModuloPartida.h
