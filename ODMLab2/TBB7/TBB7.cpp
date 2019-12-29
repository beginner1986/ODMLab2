#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <tbb/tbb.h>

// TBB7: tbb::parallel_pipeline

int main()
{
	setlocale(LC_ALL, "polish");

	// files setup
	std::ifstream inputFile;
	inputFile.open("text.txt");
	
	if(!inputFile)
	{
		std::cout << "Cannot open input file" << std::endl;
		exit(0);
	}

	std::ofstream sequenceOutputFile;
	sequenceOutputFile.open("SequenceResult.txt");
	
	std::ofstream parallelOutputFile;
	parallelOutputFile.open("ParallelResult.txt");

	// sequence
	std::string line;
	std::cout << "sequence" << std::endl;
	tbb::tick_count before = tbb::tick_count::now();
	while (std::getline(inputFile, line))
	{
		std::reverse(line.begin(), line.end());
		sequenceOutputFile << line << std::endl;
	}
	tbb::tick_count after = tbb::tick_count::now();
	std::cout << "time: " << (after - before).seconds() << "s" << std::endl << std::endl;
	inputFile.close();

	// parallel
	inputFile.open("text.txt");
	if (!inputFile)
	{
		std::cout << "Cannot open input file" << std::endl;
		exit(0);
	}
	std::cout << "parallel" << std::endl;
	before = tbb::tick_count::now();
	tbb::parallel_pipeline(
		8,
		tbb::make_filter<void, std::string>(
			tbb::filter::serial_in_order,
			[&](tbb::flow_control& fc) -> std::string {
				if (!inputFile)
					fc.stop();

				std::string input;
				std::getline(inputFile, input);

				return input;
			}
		) & 
		tbb::make_filter<std::string, std::string>(
			tbb::filter::parallel,
			[](std::string input) -> std::string {
				int n = input.size() - 1;
				for (int i = 0; i < input.size() / 2; i++, n--)
				{
					std::swap(input[i], input[n]);
				}
				
				return input;
			}
		) &
		tbb::make_filter<std::string, void>(
			tbb::filter::serial_in_order,
			[&](std::string input) -> void {
				parallelOutputFile << input << std::endl;
			}
		)
	);

	after = tbb::tick_count::now();
	std::cout << "time: " << (after - before).seconds() << "s" << std::endl << std::endl;

	// close the files
	inputFile.close();
	sequenceOutputFile.close();
	parallelOutputFile.close();

	return 0;
}