#include <iostream>

#include "Task1a/Diamond.h"

class Task1a
{
public:
	void Start()
	{
		Diamond* diamond = new Diamond();
		diamond->PrintName();

		delete diamond;
	}
};
