#pragma once
#include <vector>
#include "NaveMala.h"
using namespace std;
class NavesMalas
{
private:
	vector<NaveMala*> VNaves;
public:
	NavesMalas();
	~NavesMalas();
	void MoverNaves();
};

