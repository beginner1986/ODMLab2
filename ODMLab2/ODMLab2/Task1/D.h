#pragma once

#include <cmath>
#include "C.h"

class D : private C
{
public:
	int *dx;
private:
	int *dy;

public:
	int Avg() { return (*ax + *ay + *bx + *by + *cx + *cy) / 6; }
	int Sqrt() { return (int)sqrt(*dx); }

public:
	D(int ax, int ay, int bx, int by, int cx, int cy, int x, int y)
		: C(ax, ay, bx, by, cx, cy)
	{
		dx = new int;
		dy = new int;

		*dx = x;
		*dy = y;
	}

	~D()
	{
		delete dx;
		delete dy;
	}

	D(const D& d) : C(d)
	{
		dx = d.dx;
		dy = d.dy;
	}
};

