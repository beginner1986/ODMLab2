#include <iostream>
#include <vector>
#include <random>
#include <tbb/tbb.h>

// TBB 5: tbb:parallel_reduce

int main()
{
	//setup
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(0, 1000000);

	std::vector<int> values;

	for (int i = 0; i < 100; i++)
		values.push_back(distribution(generator));

	// sequence
	std::cout << "sequence:" << std::endl;
	tbb::tick_count before = tbb::tick_count::now();
	int min = 1000001, max = 0, sum = 0;
	for (int v : values)
	{
		if (v > max)
			max = v;

		if (v < min)
			min = v;

		sum += v;
	}
	tbb::tick_count after = tbb::tick_count::now();

	std::cout << "min:" << min << std::endl;
	std::cout << "max:" << max << std::endl;
	std::cout << "sum:" << sum << std::endl;
	std::cout << "time:" << (after - before).seconds() << "s" << std::endl << std::endl;

	// tbb::parallel_reduce
	min = 1000001, max = 0, sum = 0;
	before = tbb::tick_count::now();
	sum = tbb::parallel_reduce(
		tbb::blocked_range<int>(0, (int)values.size()),
		0,
		[&](tbb::blocked_range<int> r, int total) 
		{
			for (int i = r.begin(); i < r.end(); i++)
			{
				if (min > values[i])
					min = values[i];

				if (max < values[i])
					max = values[i];

				total += values[i];
			}

			return total;
		},
		std::plus<int>()
	);
	after = tbb::tick_count::now();

	std::cout << "min:" << min << std::endl;
	std::cout << "max:" << max << std::endl;
	std::cout << "sum:" << sum << std::endl;
	std::cout << "time:" << (after - before).seconds() << "s" << std::endl << std::endl;

	return 0;
} 