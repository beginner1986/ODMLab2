#include <iostream>
#include <functional>

// TASK 9: lambda expressions

int main()
{
	// lambda expression
	std::cout << "lambda expression" << std::endl;
	int x = 3, y = 5;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	
	auto lambda = [](int x, int& y) {
		int result = x + y;
		y = 0;
		return result;;
	};
	
	std::cout << "lambda = " << lambda(x, y) << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl << std::endl;

	// function
	std::cout << "std::function<int(int, int&)>" << std::endl;
	x = 3, y = 5;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	std::function<int(int, int&)> f =
		[](int x, int& y) {
		int result = x + y;
		y = 0;
		return result;
	};

	std::cout << "f = " << f(x, y) << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	return 0;
}