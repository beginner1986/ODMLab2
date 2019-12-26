#include <iostream>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>
#include <random>

#include "Point.h"

bool isEven(const int& i) { return (i % 2 == 0); }
bool isEvenPoint(const Point& p)
{
	return ((p.getX() % 2 == 0) && (p.getY() % 2 == 0)); 
}

int main()
{
	// containers declaration
	std::vector<int> intVec;
	std::vector<Point> pointVec;
	std::array<int, 100> intArray;
	std::array<Point, 100> pointArray;

	// RNG config
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(0, 1000000);

	// fill the containers
	for (int i = 0; i < 100; i++)
	{
		int val1 = distribution(generator);
		int val2 = distribution(generator);
		Point p(val1, val2);

		intVec.push_back(val1);
		pointVec.push_back(p);
		intArray[i] = val1;
		pointArray[i] = p;
	}

	// find_if
	std::cout << "int vector find_if" << std::endl;
	std::vector<int>::iterator itIntVec = 
		std::find_if(intVec.begin(), intVec.end(), isEven);
	std::cout << "The first even number is: " << *itIntVec << std::endl << std::endl;

	std::cout << "point vector find_if" << std::endl;
	std::vector<Point>::iterator itPointVec = 
		std::find_if(pointVec.begin(), pointVec.end(), isEvenPoint);
	std::cout << "The first even point is: ";
	itPointVec->print();
	std::cout << std::endl << std::endl;

	std::cout << "int array find_if" << std::endl;
	std::array<int, 100>::iterator itIntArray =
		std::find_if(intArray.begin(), intArray.end(), isEven);
	std::cout << "The first even number is: " << *itIntArray << std::endl << std::endl;

	std::cout << "point array find_if" << std::endl;
	std::array<Point, 100>::iterator itPointArray =
		std::find_if(pointArray.begin(), pointArray.end(), isEvenPoint);
	std::cout << "The first even point is: ";
	itPointVec->print();
	std::cout << std::endl << std::endl;

	// swap
	std::cout << "int vector swap" << std::endl;
	std::cout << "before - first value: " << intVec[0] 
		<< ", last value: " << intVec[intVec.size() - 1] << std::endl;
	std::swap(intVec[0], intVec[intVec.size() - 1]);
	std::cout << "after - first value: " << intVec[0] 
		<< ", last value: " << intVec[intVec.size() - 1] << std::endl << std::endl;

	std::cout << "point vector swap" << std::endl;
	std::cout << "before - first value: ";
	pointVec[0].print();
	std::cout << ", last value: ";
	pointVec[pointVec.size() - 1].print();
	std::cout << std::endl;
	std::swap(pointVec[0], pointVec[intVec.size() - 1]);
	std::cout << "after - first value: ";
	pointVec[0].print();
	std::cout << ", last value: ";
	pointVec[pointVec.size() - 1].print();
	std::cout << std::endl << std::endl;

	std::cout << "int array swap" << std::endl;
	std::cout << "before - first value: " << intArray[0]
		<< ", last value: " << intArray[intArray.size() - 1] << std::endl;
	std::swap(intArray[0], intArray[intArray.size() - 1]);
	std::cout << "after - first value: " << intArray[0]
		<< ", last value: " << intArray[intArray.size() - 1] << std::endl << std::endl;

	std::cout << "point array swap" << std::endl;
	std::cout << "before - first value: ";
	pointArray[0].print();
	std::cout << ", last value: ";
	pointArray[pointArray.size() - 1].print();
	std::cout << std::endl;
	std::swap(pointArray[0], pointArray[pointArray.size() - 1]);
	std::cout << "after - first value: ";
	pointArray[0].print();
	std::cout << ", last value: ";
	pointArray[pointArray.size() - 1].print();
	std::cout << std::endl << std::endl;

	// remove
	std::cout << "int vector remove" << std::endl;
	int tempInt = intVec[0];
	std::remove(intVec.begin(), intVec.end(), tempInt);
	std::cout << "All the " << tempInt << " values removed." << std::endl << std::endl;

	std::cout << "point vector remove" << std::endl;
	Point tempPoint = pointVec[0];
	auto trash1 = std::remove(pointVec.begin(), pointVec.end(), Point(0, 0));
	std::cout << "All the ";
	tempPoint.print();
	std::cout << " points removed." << std::endl << std::endl;

	std::cout << "int array remove" << std::endl;
	tempInt = intArray[0];
	auto trash2 = std::remove(intArray.begin(), intArray.end(), intArray[0]);
	std::cout << "All the " << tempInt << " values removed." << std::endl << std::endl;

	std::cout << "point array remove" << std::endl;
	tempPoint = pointArray[0];
	auto trash3 = std::remove(pointArray.begin(), pointArray.end(), Point(0, 0));
	std::cout << "All the ";
	tempPoint.print();
	std::cout << " points removed." << std::endl << std::endl;

	// sort
	std::cout << "int vector sort:" << std::endl;
	std::sort(intVec.begin(), intVec.end());
	for (int i : intVec)
		std::cout << i << " ";
	std::cout << std::endl << std::endl;

	std::cout << "point vector sort:" << std::endl;
	std::sort(pointVec.begin(), pointVec.end());
	for (Point p : pointVec)
	{
		p.print();
		std::cout << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "int array sort:" << std::endl;
	std::sort(intArray.begin(), intArray.end());
	for (int i : intArray)
		std::cout << i << " ";
	std::cout << std::endl << std::endl;

	std::cout << "point array sort:" << std::endl;
	std::sort(pointArray.begin(), pointArray.end());
	for (Point p : pointArray)
	{
		p.print();
		std::cout << " ";
	}
	std::cout << std::endl << std::endl;

	return 0;
}