#pragma once

#include "A.h"

class B : public A
{
public:
	int bx;
protected:
	int by;

public:
	int Substract() { return bx - by; }
	int Divide() { return bx / by; }

public:
	B(int ax, int ay, int x, int y) : A(ax, ay)
	{
		bx = x;
		by = y;

		std::cout << "B created" << std::endl;
	}

	virtual ~B()
	{
		std::cout << "B deleted" << std::endl;
	}

	B(const B& b) : A(b)
	{
		bx = b.bx;
		by = b.by;

		std::cout << "B copied" << std::endl;
	}
};
