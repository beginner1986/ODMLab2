#pragma once

#include <iostream>

class Base
{
public:
	~Base() = default;

	void PrintName()
	{
		std::cout << "Base" << std::endl;
	}
};