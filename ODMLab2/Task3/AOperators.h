#pragma once

#include <iostream>
#include "A.h"

inline A& A::operator=(const A& other)
{
	if (this != &other)
	{
		this->ax = other.ax;
		this->ay = other.ay;
	}

	std::cout << "= overloaded" << std::endl;
	return *this;
}

inline A& A::operator+=(const A& other)
{
	this->ax += (int)other.ax;
	this->ay += (int)other.ay;

	std::cout << "+= overloaded" << std::endl;
	return *this;
}

inline A& A::operator++()
{
	this->ax++;
	this->ay++;

	std::cout << "++ (post) overloaded" << std::endl;
	return *this;
}

inline A& A::operator++(int)
{
	++this->ax;
	++this->ay;

	std::cout << "++ (pre) overloaded" << std::endl;
	return *this;
}

inline A& A::operator+(const A& other)
{
	this->ax += (int)other.ax;
	this->ay += (int)other.ay;

	std::cout << "+ overloaded" << std::endl;
	return *this;
}

inline A& A::operator-(const A& other)
{
	this->ax -= (int)other.ax;
	this->ay -= (int)other.ay;

	std::cout << "- overloaded" << std::endl;
	return *this;
}

inline bool A::operator>(const A& other)
{
	std::cout << "> overloaded" << std::endl;

	if (this->ax > other.ax&& this->ay > other.ay)
		return true;
	else
		return false;
}

inline bool A::operator<(const A& other)
{
	std::cout << "< overloaded" << std::endl;
	
	if (this->ax < other.ax && this->ay < other.ay)
		return true;
	else
		return false;
}

inline bool A::operator==(const A& other)
{
	std::cout << "== overloaded" << std::endl;

	if (this->ax == other.ax && this->ay == other.ay)
		return true;
	else
		return false;
}

inline bool A::operator!=(const A& other)
{
	std::cout << "!= overloaded" << std::endl;
	
	if (this->ax != other.ax || this->ay != other.ay)
		return true;
	else
		return false;
}

inline int& A::operator[](size_t index)
{
	std::cout << "[] overloaded" << std::endl;

	if (index >= 10)
	{
		std::cout << "Out of bounds" << std::endl;
		return tab[0];
	}
	else
	{
		return tab[index];
	}
}

inline A& A::operator()(int ax)
{
	std::cout << "() single overloaded" << std::endl;

	this->ax += ax;
	this->ay += 10;

	return *this;
}

inline A& A::operator()(int ax, int ay)
{
	std::cout << "() double overloaded" << std::endl;

	this->ax += ax;
	this->ay += ay;
	this->ay += 10;

	return *this;
}
