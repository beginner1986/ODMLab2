#pragma once

#include <iostream>
#include "Derived1.h"
#include "Derived2.h"

class Diamond : public Derived1, Derived2
{
public:
	Diamond() = default;

	void PrintName() override
	{
		std::cout << "Diamond" << std::endl;
	}
};