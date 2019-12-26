#include <iostream>
#include <functional>

int main()
{
	std::function<int(int, int&)> f = 
		[](int x, int& y) {
		int result = x + y;
		y = 0;
		return result;
	};

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

	std::cout << "std::function<int(int, int&)>" << std::endl;
	x = 3, y = 5;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "f = " << f(x, y) << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	return 0;
}