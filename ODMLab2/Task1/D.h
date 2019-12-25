#pragma once

#include <cmath>
#include "C.h"

class D : private C
{
public:
	int dx;
private:
	int dy;
	int* tab;

public:
	int Avg() { return (ax + ay + bx + by + cx + cy) / 6; }
	int Sqrt() { return (int)sqrt(dx); }

public:
	D(int ax, int ay, int bx, int by, int cx, int cy, int x, int y)
		: C(ax, ay, bx, by, cx, cy)
	{
		dx = x;
		dy = y;
		tab = new int[10];

		std::cout << "D created" << std::endl;
	}

	~D()
	{
		std::cout << "D deleted" << std::endl;
	}

	D(const D& d) : C(d)
	{
		dx = d.dx;
		dy = d.dy;
		delete tab;

		std::cout << "D copied" << std::endl;
	}
};

