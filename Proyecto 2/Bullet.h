#pragma once
#include "Base.h"
#include <math.h>
class Bullet : public Base
{
public:
	Bullet();
	Bullet(int px, int py, int pw, int ph, int direccion);
	~Bullet();
	void Mover(Graphics^ g);
};

