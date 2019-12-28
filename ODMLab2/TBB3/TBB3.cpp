#include <iostream>
#include <vector>
#include <tbb/tbb.h>

// TBB 3: tbb::parallel_for

int main()
{
	// setup
	std::cout << "tbb::parallel_for:" << std::endl;
	std::vector<int> vector;
	for (int i = 0; i <= 100; i++)
		vector.push_back(i);

	// tbb::parallel_for
	tbb::tick_count before = tbb::tick_count::now();
	tbb::parallel_for(0, 101, 2, 
		[](int& x) {
			std::string print = std::to_string(x) + " ";
			std::cout << print;
	});
	tbb::tick_count after = tbb::tick_count::now();
	std::cout << std::endl << "time:" << (after - before).seconds() << "s" << std::endl;
	std::cout << std::endl;

	// sequence
	std::cout << "Sequence:" << std::endl;
	before = tbb::tick_count::now();
	for(int i=0; i<=100; i+=2)
		std::cout << i << " ";
	after = tbb::tick_count::now();
	std::cout << std::endl << "time:" << (after - before).seconds() << "s" << std::endl;

	return 0;
}