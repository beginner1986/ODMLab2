#pragma once

#include <iostream>

class Base
{
public:
	virtual void PrintName()
	{
		std::cout << "Base" << std::endl;
	}
};