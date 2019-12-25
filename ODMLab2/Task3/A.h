#pragma once

class A
{
public:
	int ax;
	int *tab;
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
		tab = new int[10];
		for (int i = 0; i < 10; i++)
			tab[i] = 0;

		std::cout << "A created" << std::endl;
	}

	A(int x, int y)
	{
		ax = x;
		ay = y;
		tab = new int[10];

		std::cout << "A created" << std::endl;
	}

	virtual ~A()
	{
		delete tab;
		
		std::cout << "A deleted" << std::endl;
	}

	A(const A& a)
	{
		ax = a.ax;
		ay = a.ay;

		std::cout << "A copied" << std::endl;
	}

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
	int& operator[](size_t index);
	A& operator()(int ax, int ay);
	A& operator()(int ax);
};
