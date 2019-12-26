#pragma once
#include <iostream>

class Point
{
private:
	int x, y;

public:
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}

	int getX() { return x; } const
	int getY() { return y; } const
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	void print() const { std::cout << "(" << x << ", " << y << ")"; }

	inline bool operator<(const Point& other) const
	{
		if (x < other.x)
			return true;
		else
			return false;
	}
};


