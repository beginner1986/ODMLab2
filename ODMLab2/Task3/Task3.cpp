#include <iostream>
#include "AOperators.h"

// TASK 3: operators overloading

int main()
{
	std::cout << "A instances on stack creation:" << std::endl;
	A a1(2, 3);
	A a2(1, 2);
	A a3;
	std::cout << std::endl;

	a3 = a2;
	a3 += a1;
	a3++;
	++a3;
	a3 = a1 + a2;
	a3 = a1 - a2;
	bool result = a1 > a2;
	result = a1 < a2;
	result = a1 == a2;
	result = a1 != a2;
	a3(1);
	a3(1, 2);
	int i = a2[1];

	std::cout << std::endl << "A instances on stack delete:" << std::endl;
}
