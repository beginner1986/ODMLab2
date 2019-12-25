#pragma once

#include <iostream>
#include "Base.h"

class Derived1 : public virtual Base
{
public:
	Derived1()
	{
		std::cout << "Derived1 created" << std::endl;
	}

	virtual ~Derived1()
	{
		std::cout << "Derived1 deleted" << std::endl;
	}
};