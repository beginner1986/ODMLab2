#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <random>

#include "Point.h"

// TASK 7: STL containers / iterators

void printPoint(const Point& p)
{
	p.print();
	std::cout << " ";
}

int main()
{
	// declare the containers
	std::vector<int> intVec;
	std::vector<Point> pointVec;

	std::list<int> intList;
	std::list<Point> pointList;

	std::array<int, 100> intArray;
	std::array<Point, 100> pointArray;

	std::set<int> intSet;
	std::set<Point> pointSet;

	std::map<int, int> intMap;
	std::map<int, Point> pointMap;

	std::random_device generator;
	std::uniform_int_distribution<int> distribution(-1000000, 1000000);

	// fill the containers
	for (int i = 0; i < 100; i++)
	{
		int val1 = distribution(generator);
		int val2 = distribution(generator);
		Point p = Point(val1, val2);

		intVec.push_back(val1);
		pointVec.push_back(p);

		intList.push_back(val1);
		pointList.push_back(p);
		
		intArray[i] = val1;
		pointArray[i] = p;

		intSet.insert(val1);
		pointSet.insert(p);

		intMap.insert(std::make_pair(val1, val2));
		pointMap.insert(std::make_pair(val1, p));
	}

	while (intSet.size() < 100)
	{
		intSet.insert(distribution(generator));
	}

	// print the containers with iterators
	std::cout << "----------------------- ITERATORS -----------------------" << std::endl;
	std::cout << "int vector:" << std::endl;
	for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Point vector:" << std::endl;
	for (std::vector<Point>::iterator it = pointVec.begin(); it != pointVec.end(); it++)
	{
		it->print();
		std::cout << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "int list:" << std::endl;
	for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Point list:" << std::endl;
	for (std::list<Point>::iterator it = pointList.begin(); it != pointList.end(); it++)
	{
		it->print();
		std::cout << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "int array:" << std::endl;
	for (std::array<int, 100>::iterator it = intArray.begin(); it != intArray.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Point array:" << std::endl;
	for (std::array<Point, 100>::iterator it = pointArray.begin(); it != pointArray.end(); it++)
	{
		it->print();
		std::cout << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "int set:" << std::endl;
	for (std::set<int>::iterator it = intSet.begin(); it != intSet.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Point set:" << std::endl;
	for (std::set<Point>::iterator it = pointSet.begin(); it != pointSet.end(); it++)
	{
		it->print();
		std::cout << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "int map:" << std::endl;
	for (std::map<int, int>::iterator it = intMap.begin(); it != intMap.end(); it++)
	{
		std::cout << it->first << ":" << it->second << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Point map:" << std::endl;
	for (std::map<int, Point>::iterator it = pointMap.begin(); it != pointMap.end(); it++)
	{
		std::cout << it->first << ":";
		it->second.print();
		std::cout << " ";
	}
	std::cout << std::endl << std::endl;

	// print the containers with for_each loop
	std::cout << "----------------------- FOR_EACH -----------------------" << std::endl;
	std::cout << "int vector:" << std::endl;
	std::for_each(
		intVec.begin(), intVec.end(),
		[](const int& i) { std::cout << i << " "; 
	});
	std::cout << std::endl << std::endl;

	std::cout << "point vector:" << std::endl;
	std::for_each(pointVec.begin(), pointVec.end(), printPoint);
	std::cout << std::endl << std::endl;

	std::cout << "int list:" << std::endl;
	std::for_each(
		intList.begin(), intList.end(),
		[](const int& i) { std::cout << i << " "; 
	});
	std::cout << std::endl << std::endl;

	std::cout << "point list:" << std::endl;
	std::for_each(pointList.begin(), pointList.end(), printPoint);
	std::cout << std::endl << std::endl;

	std::cout << "int array:" << std::endl;
	std::for_each(
		intArray.begin(), intArray.end(),
		[](const int& i) {
			std::cout << i << " ";
	});
	std::cout << std::endl << std::endl;

	std::cout << "point array:" << std::endl;
	std::for_each(pointArray.begin(), pointArray.end(), printPoint);
	std::cout << std::endl << std::endl;

	std::cout << "int set:" << std::endl;
	std::for_each(
		intSet.begin(), intSet.end(),
		[](const int& i) {
			std::cout << i << " ";
	});
	std::cout << std::endl << std::endl;
	
	std::cout << "point set:" << std::endl;
	std::for_each(pointSet.begin(), pointSet.end(), printPoint);
	std::cout << std::endl << std::endl;

	std::cout << "int map:" << std::endl;
	std::for_each(
		intMap.begin(), intMap.end(),
		[](const std::pair<int, int>& e) {
			std::cout << e.first << ":" << e.second << " ";
	});
	std::cout << std::endl << std::endl;

	std::cout << "point map:" << std::endl;
	std::for_each(
		pointMap.begin(), pointMap.end(),
		[](const std::pair<int, Point> e) {
			std::cout << e.first << ":";
			e.second.print();
			std::cout << " ";
	});
	std::cout << std::endl << std::endl;

	return 0;
}
