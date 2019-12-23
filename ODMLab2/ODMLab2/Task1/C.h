#pragma once

#include "B.h"

class C : protected B
{
public:
	int *cx;
protected:
	int *cy;

public:
	int Mod() { return *cx % *cy; }
	int Square() { return *cx * *cx; }

public:
	C(int ax, int ay, int bx, int by, int x, int y) : B(ax, ay, bx, by)
	{
		cx = new int;
		cy = new int;

		*cx = x;
		*cy = y;
	}

	~C()
	{
		delete cx;
		delete cy;
	}

	C(const C& c) : B(c)
	{
		cx = c.cx;
		cy = c.cy;
	}
};
