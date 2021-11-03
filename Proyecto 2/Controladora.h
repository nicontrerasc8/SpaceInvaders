#pragma once
#include <vector>
#include "NaveEspacial.h"
#include "NaveMala.h"
#include "Castle.h"
using namespace std;
class Controladora
{
private:
	int N;
	int CantidadDeNavesEliminadas, CantidadDeVidas;
	bool gano, perdio;
	vector<NaveMala*> arreglo;
	NaveEspacial* objNave;
	Castle* objCastillo;
	time_t TiempoGracia;

public:
	Controladora(Graphics^ g);
	~Controladora();
	void DibujarNave(Graphics^ g, Bitmap^ bpm);
	void DibujarEnemigos(Graphics^ g, Bitmap^ bpm);
	void DesplazarNave(direccion nuevo);
	void ColisionBalas_NavesMalas();
	void ColisionNaves();
	bool ReturnGano();
	bool ReturnPerdio();
	bool SeAcaboElJuego();
	void Disparar();
	void DibujarBalas(Graphics^ g, Bitmap^ bpm);
	void DibujarBombas(Graphics^ g, Bitmap^ bpm);
};

