//Silvia Rodrigo Cañete 
#pragma once

#ifndef ModuloListaPartidas_h
#define ModuloListaPartidas_h

#include"ModuloPartida.h"
#include<iostream>

const int MAX_PARTIDAS = 20;
struct tListaPartidas {
	int nElem = 0;
	tPartida* datos[MAX_PARTIDAS];
};

ifstream& operator>>(ifstream& archivo, tListaPartidas& listaPartidas);
ofstream& operator<<(ofstream& archivo, const tListaPartidas& listaPartidas);

void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida);
void destruyeListaPartidas(tListaPartidas& listaPartidas);
void intercambiar(tPartida*& x, tPartida*& y);
int buscaPos(const tListaPartidas& listaPartidas, int nivel);
tPartida* dameElem(const tListaPartidas& listaPartidas, int pos);
int dameNumElem(const tListaPartidas& listaPartidas);
void eliminarPartida(tListaPartidas& listaPartidas, const tPartida& partida);


#endif // !ModuloListaPartidas.h
