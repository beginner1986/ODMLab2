#pragma once

#include <iostream>

class Abstract
{
public:
	Abstract()
	{
		std::cout << "Abstract created" << std::endl;

	}
	
	virtual ~Abstract()
	{
		std::cout << "Abstract deleted" << std::endl;
	}

	virtual void Hello() = 0;

	virtual void FinalFunction()
	{
		std::cout << "Final function in base class" << std::endl;
	}
};
