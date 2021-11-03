#include "NaveEspacial.h"

NaveEspacial::NaveEspacial()
{
}

NaveEspacial::NaveEspacial(int px, int py, int pw, int ph) : Base(px, py, pw, ph, 1, 1, 0, 0)
{
	MovX = 3;
	Desplazamiento(direccion::derecha);
}

NaveEspacial::~NaveEspacial()
{
}

void NaveEspacial::Disparar()
{
	arrBalas.push_back(new Bullet(x + w / 2, y, 1, 1, 2));
}

void NaveEspacial::MoverBalas(Graphics^ g, Bitmap^ bpm)
{
	for (int i = 0; i < arrBalas.size(); i++)
	{
		arrBalas.at(i)->DibujarDesdeImagen(g, bpm);
		arrBalas.at(i)->Mover(g);
	}
	for (int i = 0; i < arrBalas.size(); i++)
	{
		if (arrBalas.at(i)->RetornarEliminar() == true) {
			arrBalas.erase(arrBalas.begin() + i);
		}
	}
}

void NaveEspacial::Mover(Graphics^ g)
{
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width) dx = 0;
	if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height) dy = 0;
	x += dx;
	y += dy;
}

void NaveEspacial::Desplazamiento(direccion nueva)
{
	orientacion = nueva;
	dx = dy = 0;
	if (orientacion == direccion::izquierda) {
		dx = -w / MovX;
		fil = 0;
	}
	if (orientacion == direccion::derecha) {
		dx = w / MovX;
		fil = 0;
	}
}

vector<Bullet*> NaveEspacial::RetornarBalas()
{
	return arrBalas;
}

int NaveEspacial::RetornarCantBalas()
{
	return arrBalas.size();
}

Bullet* NaveEspacial::RetornarIndiceBala(int i)
{
	return arrBalas.at(i);
}

