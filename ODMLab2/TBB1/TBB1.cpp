#include <iostream>
#include <functional>
#include <tbb/tbb.h>

// TBB 1: parallel_invoke

void function()
{
	for (int i = 0; i < 8; i++)
		std::cout << "Hello World!\n";
}

class Print
{
public:
	void operator() () const
	{
		for (int i = 0; i < 8; i++)
			std::cout << "Hello World!\n";
	}
};

int main()
{
	// functional object
	std::cout << "Functor object:" << std::endl;
	Print print;

	tbb::tick_count before = tbb::tick_count::now();
	tbb::parallel_invoke(print, print);
	tbb::tick_count after = tbb::tick_count::now();
	std::cout << "time:" << (after - before).seconds() << "s" << std::endl;

	// lambda
	std::cout << "\nLambda:" << std::endl;
	auto lambda = []() {
		for(int i=0; i<8; i++)
			std::cout << "Hello World!\n"; 
	};

	before = tbb::tick_count::now();
	tbb::parallel_invoke(lambda, lambda);
	after = tbb::tick_count::now();
	std::cout << "time:" << (after - before).seconds() << "s" << std::endl;

	// function pointer
	std::cout << "\nFunction pointer:" << std::endl;
	const auto funcPtr = function;	// void(* const funcPtr)() = function;
	
	before = tbb::tick_count::now();
	tbb::parallel_invoke(funcPtr, funcPtr);
	after = tbb::tick_count::now();
	std::cout << "time:" << (after - before).seconds() << "s" << std::endl;

	// sequence
	before = tbb::tick_count::now();
	for (int i = 0; i < 16; i++)
		std::cout << "Hello World!" << std::endl;
	after = tbb::tick_count::now();
	std::cout << "time:" << (after - before).seconds() << "s" << std::endl;

	return 0;
}