#include <iostream>
#include <functional>

// TASK 9: lambda expressions

class Add
{
public:
	Add() {};
	int operator() (int x, int& y) { 
		auto f = [](int x, int& y) {
			int result = x + y;
			y = 0;
			return result; 
		};

		return f(x, y);
	}
};

int main()
{
	// lambda expression
	std::cout << "lambda expression" << std::endl;
	int x = 3, y = 5;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	
	std::function<int(int, int&)> lambda =
		[](int x, int& y) {
		int result = x + y;
		y = 0;
		return result;
	};
	
	std::cout << "lambda = " << lambda(x, y) << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl << std::endl;

	// functional class
	std::cout << "Add()" << std::endl;
	x = 3, y = 5;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	Add add = Add();
	std::cout << "Add(x, y) = " << add(x, y) << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	return 0;
}