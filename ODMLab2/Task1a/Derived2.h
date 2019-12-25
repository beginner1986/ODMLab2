#pragma once

#include <iostream>
#include "Base.h"

class Derived2 : public virtual Base
{
public:
	Derived2()
	{
		std::cout << "Derived2 created" << std::endl;
	}

	virtual ~Derived2()
	{
		std::cout << "Derived2 deleted" << std::endl;
	}
};