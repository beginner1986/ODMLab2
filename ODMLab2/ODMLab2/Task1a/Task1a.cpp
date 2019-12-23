#include <iostream>

#include "Task1a/Diamond.h"

// TASK 1a: virtual inheritance

class Task1a
{
public:
	void Start()
	{
		Diamond diamond;
		Base* base = &diamond;
		base->PrintName();
	}
};
