#pragma once

#include <iostream>
#include "Abstract.h"

class Middle : public Abstract
{
public:
	Middle()
	{
		std::cout << "Middle created" << std::endl;
	}

	virtual ~Middle()
	{
		std::cout << "Middle deleted" << std::endl;
	}

	void Hello() override
	{
		std::cout << "Hello Middle" << std::endl;
	}

	virtual void Bye()
	{
		std::cout << "Bye Middle" << std::endl;
	}

	void FinalFunction() final override
	{
		std::cout << "Final function in middle class" << std::endl;
	}
};