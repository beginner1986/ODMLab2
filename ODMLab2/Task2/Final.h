#pragma once

#include <iostream>
#include "Middle.h"

class Final final: public Middle
{
public:
	Final()
	{
		std::cout << "Final created" << std::endl;
	}

	virtual ~Final()
	{
		std::cout << "Final deleted" << std::endl;
	}

	void Hello() override
	{
		std::cout << "Hello Final" << std::endl;
	}

	void Bye() override
	{
		std::cout << "Bye Final" << std::endl;
	}
};