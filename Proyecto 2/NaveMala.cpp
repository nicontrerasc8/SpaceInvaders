#include "NaveMala.h"

NaveMala::NaveMala()
{
	TiempoDisparoBalas = time(0);
}

NaveMala::NaveMala(int px, int py, int pw, int ph , int GraphicsHeightVariable) : Base(px, py, pw, ph, 3, 7, 0, 0)
{
	x = rand()%1000 + 10;
	y = rand() % (GraphicsHeightVariable / 2) + 1;
	dx = rand()% 10 + 1;
	dy = 0;
	TiempoDisparoBalas = time(0);
}

NaveMala::~NaveMala()
{
}

void NaveMala::InsertarBomba()
{
	if (difftime(time(0), TiempoDisparoBalas) > rand()%120 +1) {
		arrBombas.push_back(new Bomba(x + w / 2, y, 0, 0));
		TiempoDisparoBalas = time(0);
	}
}

void NaveMala::MoverBombas(Graphics^ g, Bitmap^ bpm)
{
	InsertarBomba();
	for (int i = 0; i < arrBombas.size(); i++)
	{
		arrBombas.at(i)->DibujarDesdeImagen(g, bpm);
		arrBombas.at(i)->Mover(g);
	}
	for (int i = 0; i < arrBombas.size(); i++)
	{
		if (arrBombas.at(i)->RetornarEliminar() == true) {
			arrBombas.erase(arrBombas.begin() + i);
		}
	}
}

vector<Bomba*> NaveMala::RetornarBalas()
{
	return arrBombas;
}

int NaveMala::RetornarCantBalas()
{
	return arrBombas.size();
}

Bomba* NaveMala::RetornarIndiceBala(int i)
{
	return arrBombas.at(i);
}
