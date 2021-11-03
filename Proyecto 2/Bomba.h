#pragma once
#include "Base.h"
class Bomba : public Base
{
public: 
	Bomba();
	Bomba(int px, int py, int pw, int ph);
	~Bomba();
	void Mover(Graphics ^g);
};

