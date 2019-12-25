#pragma once

#include "B.h"

class C : protected B
{
public:
	int cx;
protected:
	int cy;

public:
	int Mod() { return cx % cy; }
	int Square() { return cx * cx; }

public:
	C()
	{
		cx = 0;
		cy = 0;

		std::cout << "C created" << std::endl;
	}

	C(int ax, int ay, int bx, int by, int x, int y) : B(ax, ay, bx, by)
	{
		cx = x;
		cy = y;

		std::cout << "C created" << std::endl;
	}

	virtual ~C()
	{
		std::cout << "C deleted" << std::endl;
	}

	C(const C& c) : B(c)
	{
		cx = c.cx;
		cy = c.cy;

		std::cout << "C copied" << std::endl;
	}
};
