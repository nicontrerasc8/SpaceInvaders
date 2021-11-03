#include "NavesMalas.h"

NavesMalas::NavesMalas()
{
	int N = 20;
	for (int i = 0; i < N; i++)
	{
		VNaves.push_back(new NaveMala*);
	}
}

NavesMalas::~NavesMalas()
{
}

void NavesMalas::MoverNaves()
{
}
