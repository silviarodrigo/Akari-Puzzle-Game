//Silvia Rodrigo Cañete 

#pragma once

#ifndef ModuloJuego_h
#define ModuloJuego_h
#include"ModuloPosicion.h"
#include"ModuloTablero.h"
#include<iostream>
using namespace std;

//arrays con las posiciones para comprobar las cuatro casillas adyacentes a una
const int incF[8] = { 1,-1,-1, 1 };
const int incC[8] = { 0,1, -1,-1 };

void ejecutarPos(tTablero& tablero, tPos pos);
void cambiarIluminacion(tTablero& tablero, tPos pos, bool iluminar);
void cambiarIluminacionDir(tTablero& tablero, tPos pos, tDir dir, bool iluminar);
bool hasGanado(const tTablero& tablero);
bool seCumpleRestriccionFin(const tTablero& tablero, tPos pos);
int numBombillasVecinas(const tTablero& tablero, tPos pos);
void resetearJuego(tTablero& tablero);


#endif // !ModuloJuego_h

