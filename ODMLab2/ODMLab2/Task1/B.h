#pragma once

#include "A.h"

class B : public A
{
public:
	int *bx;
protected:
	int *by;

public:
	int Substract() { return *bx - *by; }
	int Divide() { return *bx / *by; }

public:
	B(int ax, int ay, int x, int y) : A(ax, ay)
	{
		bx = new int;
		by = new int;

		*bx = x;
		*by = y;
	}

	virtual ~B()
	{
		delete bx;
		delete by;
	}

	B(const B& b) : A(b)
	{
		bx = b.bx;
		by = b.by;
	}
};

