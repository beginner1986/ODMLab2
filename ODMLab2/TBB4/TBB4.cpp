#include <iostream>
#include <list>
#include <random>
#include <algorithm>
#include <tbb/tbb.h>

// TBB 4: tbb::parallel_do

bool isPrime(int x);

int main()
{
	//setup
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(2, 1000000);

	std::list<std::pair<int, bool> > values1;
	std::list<std::pair<int, bool> > values2;
	for (int i = 0; i < 100; i++)
	{
		int val = distribution(generator);
		values1.push_back(std::pair<int, bool>(val, false));
		values2.push_back(std::pair<int, bool>(val, false));
	}

	// sequence
	std::cout << "Sequence isPrime check: " << std::endl;
	tbb::tick_count before = tbb::tick_count::now();
	for (std::list<std::pair<int, bool> >::reference v : values1)
		if (isPrime(v.first))
			v.second = true;
	tbb::tick_count after = tbb::tick_count::now();
	std::cout << "time: " << (after - before).seconds() << "s" << std::endl;

	values1.sort([](const std::pair<int, bool>& x, const std::pair<int, bool>& y) {
		return x.first < y.first;
	});

	for (std::pair<int, bool> pv : values1)
	{
		if (pv.second)
			std::cout << pv.first << " ";
	}
	std::cout << std::endl << std::endl;


	// parallel
	std::cout << "Parallel isPrime check: " << std::endl;
	before = tbb::tick_count::now();
	tbb::parallel_do(values2, [](std::list<std::pair<int, bool> >::reference v) {
		if (isPrime(v.first))
			v.second = true;
	});
	after = tbb::tick_count::now();
	std::cout << "time: " << (after - before).seconds() << "s" << std::endl;

	values2.sort([](const std::pair<int, bool>& x, const std::pair<int, bool>& y) {
		return x.first < y.first;
		});

	for (std::pair<int, bool> v : values1)
	{
		if (v.second)
			std::cout << v.first << " ";
	}

	return 0;
}

bool isPrime(int x)
{
	if (x < 2)
		return false;

	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;

	return true;
}
