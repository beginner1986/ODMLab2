#pragma once

class A
{
public:
	int ax;
protected:
	int ay;

public:
	int Add() { return ax + ay; }
	int Multiply() { return ax * ay; }

public:
	A()
	{
		ax = 0;
		ay = 0;

		std::cout << "A created" << std::endl;
	}

	A(int x, int y)
	{
		ax = x;
		ay = y;

		std::cout << "A created" << std::endl;
	}

	virtual ~A()
	{
		std::cout << "A deleted" << std::endl;
	}

	A(const A &a)
	{
		ax = a.ax;
		ay = a.ay;

		std::cout << "A copied" << std::endl;
	}
};
