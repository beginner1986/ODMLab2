#include <iostream>

#include "Diamond.h"

// TASK 1a: virtual inheritance

int main()
{
	std::cout << "Diamond on the stack:" << std::endl;
	Diamond diamond;

	std::cout << std::endl << "Base* base = new Diamond():" << std::endl;
	Base* base = new Diamond();

	std::cout << std::endl << "base->PrintName():" << std::endl;
	base->PrintName();
		
	std::cout << std::endl << "delete Base (new Diamond):" << std::endl;
	delete base;

	std::cout << std::endl << "delete stack Diamond:" << std::endl;

	return 0;
}
