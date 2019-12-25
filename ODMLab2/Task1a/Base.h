#pragma once

#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base created" << std::endl;
	}

	virtual ~Base()
	{
		std::cout << "Base deleted" << std::endl;
	}

	virtual void PrintName()
	{
		std::cout << "Base method" << std::endl;
	}
};