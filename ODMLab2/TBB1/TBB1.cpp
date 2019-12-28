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

	tbb::parallel_invoke(print, print);

	// lambda
	std::cout << "\nLambda:" << std::endl;
	auto lambda = []() {
		for(int i=0; i<8; i++)
			std::cout << "Hello World!\n"; 
	};

	tbb::parallel_invoke(lambda, lambda);

	// function pointer
	std::cout << "\nFunction pointer:" << std::endl;
	const auto funcPtr = function;	// void(* const funcPtr)() = function;
	tbb::parallel_invoke(funcPtr, funcPtr);

	return 0;
}