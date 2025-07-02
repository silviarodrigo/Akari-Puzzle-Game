//Silvia Rodrigo Cañete

#pragma once

#ifndef ModuloPosicion_h
#define ModuloPosicion_h


#include<iostream>

using namespace std;

struct tPos {
	int i, j;
};

enum tDir
{
	NORTE,
	SUR,
	ESTE,
	OESTE
};

istream& operator>>(istream& in, tPos& pos);

bool PosCorrecta(const tPos& pos, int nFils, int nCols);
void pedirPos(tPos& pos);
void avanzarPosDir(tPos& pos, const tDir& idr);
bool esPosQuit(const tPos& pos);
bool esPosReset(const tPos& pos);

#endif // !ModuloPosicion_h
