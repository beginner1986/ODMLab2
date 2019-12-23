#pragma once

class A
{
public:
	int *ax;
protected:
	int *ay;

public:
	int Add() { return *ax + *ay; }
	int Multiply() { return *ax * *ay; }

public:
	A(int x, int y)
	{
		ax = new int;
		ay = new int;

		*ax = x;
		*ay = y;
	}

	virtual ~A()
	{
		delete ax;
		delete ay;
	}

	A(const A &a)
	{
		ax = a.ax;
		ay = a.ay;
	}
};

