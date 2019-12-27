#pragma once

#include<iostream>

// base template calss
template<class T>
class Point2D
{
private:
	T x, y;

public:
	Point2D(T _x, T _y) : x(_x), y(_y) {}
	T getX() const { return x; }
	T getY() const { return y; }
	void setX(T x) { this->x = x; }
	void setY(T y) { this->y = y; }

	virtual void print() { std::cout << "(" << x << ", " << y << ")" << std::endl; }
};

// non-template inheritance
class Entity : public Point2D<double>
{
private:
	char name;

public:
	explicit Entity(double x, double y, char name) : Point2D(x, y) { this->name = name; }

	void print() override
	{
		std::cout << name << "(" 
			<< this->getX() << ", " 
			<< this->getY() << ")" << std::endl;
	}
};

// template inheritance
template<class T>
class Point3D : public Point2D<T>
{
private:
	T z;

public:
	Point3D(T _x, T _y, T _z) : Point2D<T>(_x, _y), z(_z) {}
	T getZ() const { return z; }
	void setZ(T z) { this->z = z; }

	void print() override
	{
		std::cout << "(" << this->getX() << ", " 
			<< this->getY() << ", " 
			<< this->getZ() << ")" << std::endl;
	}
};

// specialized class
template<>
class Point3D<double>
{
private:
	double x, y, z;
public:
	explicit Point3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

	bool operator==(const Point3D<double>& other)
	{
		if (compare(x, other.x) && compare(y, other.y) && compare(z, other.z))
			return true;
		else
			return false;
	}

	void print()
	{
		std::cout << "(" << x << ", " << y << ", " << z << ") - specialized" << std::endl;
	}

private:
	bool compare(double a, double b)
	{
		if (a - b < 0.001)
			return true;
		else
			return false;
	}
};
