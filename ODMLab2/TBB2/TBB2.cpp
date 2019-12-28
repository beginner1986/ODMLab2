#include <iostream>
#include <vector>
#include <random>
#include <tbb/tbb.h>

// TBB2: tbb::parallel_for_each

int main()
{
	// setup
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(1, 1000000);

	std::vector<int> vector;
	for (int i = 0; i < 100; i++)
		vector.push_back(distribution(generator));

	// tbb::parallel_for_each
	tbb::tick_count before = tbb::tick_count::now();
	tbb::parallel_for_each(vector.begin(), vector.end(), 
		[&](int& i) {
			std::string print = std::to_string(i) + " ";
			std::cout << print;
	});
	tbb::tick_count after = tbb::tick_count::now();
	std::cout << std::endl << "time: " << (after - before).seconds() << "s" 
		<< std::endl << std::endl;;

	// sequence
	before = tbb::tick_count::now();
	for (int i : vector)
	{
		std::cout << i << " ";
	}
	after = tbb::tick_count::now();
	std::cout << std::endl << "time: " << (after - before).seconds() << "s" << std::endl;

	return 0;
}
