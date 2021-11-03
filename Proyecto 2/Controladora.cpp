#include "Controladora.h"

Controladora::Controladora(Graphics^ g)
{
	N = 40;
	for (size_t i = 0; i < N; i++)
		arreglo.push_back(new NaveMala(rand() % 100 + 1, rand() % 50 + 1, 1, 1, g->VisibleClipBounds.Height));

	objNave = new NaveEspacial(g->VisibleClipBounds.Width / 2, g->VisibleClipBounds.Height - 40, 1, 1);
	objCastillo = new Castle(g->VisibleClipBounds.Width, g->VisibleClipBounds.Height, 1, 1);
	CantidadDeNavesEliminadas = 0;
	CantidadDeVidas = 3;
	TiempoGracia = time(0);
	gano = false;
	perdio = false;
}

Controladora::~Controladora()
{
	delete objNave;
	for (int i = 0; i < arreglo.size(); i++)
		delete arreglo.at(i);
	arreglo.clear();
}


void Controladora::DibujarNave(Graphics^ g, Bitmap^ bpm)
{
	objNave->DibujarDesdeImagen(g, bpm);
	objNave->Mover(g);
}


void Controladora::DibujarEnemigos(Graphics^ g, Bitmap^ bpm)
{
	for (int i = 0; i < arreglo.size(); i++)
	{
		arreglo.at(i)->DibujarDesdeImagen(g,bpm);
		arreglo.at(i)->Mover(g);
	}
	for (int i = 0; i < arreglo.size(); i++)
	{
		if (arreglo.at(i)->RetornarEliminar() == true) {
			arreglo.erase(arreglo.begin() + i);
		}
	}
}

void Controladora::DesplazarNave(direccion nuevo)
{
	objNave->Desplazamiento(nuevo);
}

void Controladora::ColisionBalas_NavesMalas()
{
	for (int i = 0; i < objNave->RetornarCantBalas(); i++)
	{
		System::Drawing::Rectangle r1;
		r1.X = objNave->RetornarIndiceBala(i)->RetornarX();
		r1.Y = objNave->RetornarIndiceBala(i)->RetornarY();
		r1.Width = objNave->RetornarIndiceBala(i)->RetornarW();
		r1.Height = objNave->RetornarIndiceBala(i)->RetornarH();
		for (int k = 0; k < arreglo.size(); k++)
		{
			System::Drawing::Rectangle r2;
			r2.X = arreglo.at(k)->RetornarX();
			r2.Y = arreglo.at(k)->RetornarY();
			r2.Width = arreglo.at(k)->RetornarW();
			r2.Height = arreglo.at(k)->RetornarH();
			if (r1.IntersectsWith(r2)) {
				++CantidadDeNavesEliminadas;
				objNave->RetornarIndiceBala(i)->CambiarEliminar(true);
				arreglo.at(k)->CambiarEliminar(true);
			}
		}
	}
}

void Controladora::ColisionNaves()
{
	System::Drawing::Rectangle r1;
	r1.X = objNave->RetornarX();
	r1.Y = objNave->RetornarY();
	r1.Width = objNave->RetornarW();
	r1.Height = objNave->RetornarH();
	for (int k = 0; k < arreglo.size(); k++)
	{
		for (int j = 0; j < arreglo.at(k)->RetornarCantBalas(); j++)
		{
			System::Drawing::Rectangle r2;
			r2.X = arreglo.at(k)->RetornarIndiceBala(j)->RetornarX();
			r2.Y = arreglo.at(k)->RetornarIndiceBala(j)->RetornarY();
			r2.Width = arreglo.at(k)->RetornarIndiceBala(j)->RetornarW();
			r2.Height = arreglo.at(k)->RetornarIndiceBala(j)->RetornarH();
			if (r1.IntersectsWith(r2) && difftime(time(0), TiempoGracia) > 1) {
				--CantidadDeVidas;
				TiempoGracia = time(0);
			}
		}
	}
}

bool Controladora::ReturnGano()
{
	if (arreglo.size() == 0) gano = true;
	return gano;
}

bool Controladora::ReturnPerdio()
{
	if (CantidadDeVidas == 0) perdio = true;
	return perdio;
}

bool Controladora::SeAcaboElJuego()
{
	bool Condicional = false;
	if (ReturnGano() || ReturnPerdio()) Condicional = true;
	return Condicional;
}

void Controladora::Disparar()
{
	objNave->Disparar();
}

void Controladora::DibujarBalas(Graphics^ g, Bitmap^ bpm)
{
	objNave->MoverBalas(g, bpm);
}

void Controladora::DibujarBombas(Graphics^ g, Bitmap^ bpm)
{
	for (int i = 0; i < arreglo.size(); i++)
		arreglo.at(i)->MoverBombas(g, bpm);
}


