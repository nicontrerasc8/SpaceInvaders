#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(int px, int py, int pw, int ph, int Direccion) : Base(px,py,pw,ph,4,4,0,0)
{
	if (Direccion == 1) {
		dy = 10;
	}
	if (Direccion == 2) {
		dy = -10;
	}
}

Bullet::~Bullet()
{
}

void Bullet::Mover(Graphics^ g)
{
	if (y + dy < 1)
	{
		dy = 0;
		Eliminar = true;
	}
	y += dy;
}
