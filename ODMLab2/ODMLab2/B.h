#pragma once

#include "A.h"

class B : public A
{
public:
	int *bx;
protected:
	int *by;

public:
	int Substract(int x, int y) { return x - y; }
	int Divide(int x, int y) { return x / y; }

public:
	B(int ax, int ay, int x, int y) : A(ax, ay)
	{
		bx = new int;
		by = new int;

		*bx = x;
		*by = y;
	}

	~B()
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

