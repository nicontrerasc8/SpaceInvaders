#pragma once
#include "Base.h"
#include "Bomba.h"
#include <vector>
using namespace std;
class NaveMala : public Base
{
private:
	vector<Bomba*> arrBombas;
	time_t TiempoDisparoBalas;
public:
	NaveMala();
	NaveMala(int px, int py, int pw, int ph, int GraphicsHeightVariable);
	~NaveMala();
	void InsertarBomba();
	void MoverBombas(Graphics^ g, Bitmap^ bpm);
	vector<Bomba*> RetornarBalas();
	int RetornarCantBalas();
	Bomba* RetornarIndiceBala(int i);
};

