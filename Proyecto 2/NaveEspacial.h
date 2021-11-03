#pragma once
#include "Base.h"
#include "Bullet.h"
#include <vector>
using namespace std;
class NaveEspacial : public Base
{
private:
	vector<Bullet*> arrBalas;
public:
	NaveEspacial();
	NaveEspacial(int px, int py, int pw, int ph);
	~NaveEspacial();
	void Disparar();
	void MoverBalas(Graphics^ g, Bitmap ^ bpm);
	void Mover(Graphics^ g);
	void Desplazamiento(direccion nueva);
	vector<Bullet*> RetornarBalas();
	int RetornarCantBalas();
	Bullet* RetornarIndiceBala(int i);
};

