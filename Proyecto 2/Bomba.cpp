#include "Bomba.h"

Bomba::Bomba()
{
}

Bomba::Bomba(int px, int py, int pw, int ph) : Base(px, py, pw, ph, 1, 1, 0, 0)
{
	dy = 10;
}

Bomba::~Bomba()
{
}

void Bomba::Mover(Graphics^ g)
{
	if (y + dy + h > g->VisibleClipBounds.Height)
	{
		dy = 0;
		Eliminar = true;
	}
	y += dy;
}
