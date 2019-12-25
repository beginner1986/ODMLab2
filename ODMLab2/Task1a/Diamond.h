#pragma once

#include <iostream>
#include "Derived1.h"
#include "Derived2.h"

class Diamond : public Derived1, Derived2
{
public:
	Diamond()
	{
		std::cout << "Diamond created" << std::endl;
	}

	virtual ~Diamond()
	{
		std::cout << "Diamond deleted" << std::endl;
	}

	void PrintName() override
	{
		std::cout << "Diamond method" << std::endl;
	}
};