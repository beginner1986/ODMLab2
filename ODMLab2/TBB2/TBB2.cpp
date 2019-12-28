#include <iostream>
#include <vector>
#include <random>
#include <tbb/tbb.h>

// TBB2: tbb::parallel_for_each

int main()
{
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(1, 1000000);

	std::vector<int> vector;
	for (int i = 0; i < 100; i++)
		vector.push_back(distribution(generator));

	tbb::parallel_for_each(vector.begin(), vector.end(), 
		[&](int& i) {
			std::cout << i << " ";
	});
	std::cout << std::endl;

	return 0;
}
