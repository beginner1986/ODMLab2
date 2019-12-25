#pragma once

#include <iostream>
#include "Middle.h"

class Final final: public Middle
{
public:
	void Hello() override
	{
		std::cout << "Hello Final" << std::endl;
	}

	void Bye() override
	{
		std::cout << "Bye Final" << std::endl;
	}
};