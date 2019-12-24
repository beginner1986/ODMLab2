#pragma once

// operators overloading for Task3
#include "../Task3/AOperators.h"

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
	A()
	{
		ax = new int;
		ay = new int;

		ax = 0;
		ay = 0;
	}

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

	// Operators overloading for Task 3
	A& operator=(const A& other);
	A& operator+=(const A& other);
	A& operator++();
	A& operator++(int);
	A& operator+(const A& other);
	A& operator-(const A& other);
	bool operator>(const A& other);
	bool operator<(const A& other);
	bool operator==(const A& other);
	bool operator!=(const A& other);
	A& operator[](int index);
	A& operator()(int ax, int ay);
	A& operator()(int ax);
};
