#include <iostream>
#include <functional>
#include <list>
#include <algorithm>
#include <random>

// TASK 10: lambda functions part II

int main()
{
	// lambda 1
	int x = 7;
	int y = 4;

	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::function<int()> lambda1 = [x, &y]() -> int { return x + y; };
	std::cout << "lambda1 = [x, &y]() -> int { return x + y; } = " << lambda1() << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;

	// lambda 2
	std::cout << "lambda2 = [&]() { x = 0; y = 0;  }" << std::endl;
	std::function<void()> lambda2 = [&]() { x = 0; y = 0;  };
	lambda2();
	std::cout << "x = " << x << ", y = " << y << std::endl;

	// lambda 3
	std::list<int> listCatch;
	std::list<int> listParam;

	std::random_device generator;
	std::uniform_int_distribution<int> distribution(1, 100);

	for (int i = 0; i < 10; i++)
	{
		listCatch.push_back(distribution(generator));
		listParam.push_back(distribution(generator));
	}

	auto lambda3 = [&listCatch](std::list<int>& input){
		std::list<int> *result = new std::list<int>;
		std::list<int>::iterator it1 = listCatch.begin();

		for (auto it2=input.begin(); it1 != listCatch.end(); it1++, it2++)
		{
			result->push_back(*it1 + *it2);
		}

		return result;
	};

	std::cout << "lambda 3:" << std::endl;
	std::list<int> *result = lambda3(listParam);

	for (int i : *result)
		std::cout << i << " ";
	std::cout << std::endl;

	delete result;

	return 0;
}