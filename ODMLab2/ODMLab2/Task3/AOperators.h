#pragma once

inline A& A::operator=(const A& other)
{
	if (this != &other)
	{
		this->ax = other.ax;
		this->ay = other.ay;
	}

	return *this;
}

inline A& A::operator+=(const A& other)
{
	this->ax += (int)other.ax;
	this->ay += (int)other.ay;

	return *this;
}

inline A& A::operator++()
{
	this->ax++;
	this->ay++;

	return *this;
}

inline A& A::operator++(int)
{
	++this->ax;
	++this->ay;

	return *this;
}

inline A& A::operator+(const A& other)
{
	this->ax += (int)other.ax;
	this->ay += (int)other.ay;

	return *this;
}

inline A& A::operator-(const A& other)
{
	this->ax -= (int)other.ax;
	this->ay -= (int)other.ay;

	return *this;
}

inline bool A::operator>(const A& other)
{
	if (this->ax > other.ax&& this->ay > other.ay)
		return true;
	else
		return false;
}

inline bool A::operator<(const A& other)
{
	if (this->ax < other.ax && this->ay < other.ay)
		return true;
	else
		return false;
}

inline bool A::operator==(const A& other)
{
	if (this->ax == other.ax && this->ay == other.ay)
		return true;
	else
		return false;
}

inline bool A::operator!=(const A& other)
{
	if (this->ax != other.ax || this->ay != other.ay)
		return true;
	else
		return false;
}

inline A& A::operator[](int index)
{
	if (index >= 0)
	{
		return *(this + index * sizeof(A));
	}
	else
		return *this;
}

inline A& A::operator()(int ax)
{
	this->ax += ax;
	this->ay += 10;

	return *this;
}

inline A& A::operator()(int ax, int ay)
{
	this->ax += ax;
	this->ay += ay;
	this->ay += 10;

	return *this;
}
