#pragma once

#include <iostream>

class Abstract
{
public:
	virtual void Hello() = 0;

	virtual void FinalFunction()
	{
		std::cout << "Final function in base class" << std::endl;
	}
};
