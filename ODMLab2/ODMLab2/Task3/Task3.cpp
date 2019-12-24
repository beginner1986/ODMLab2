#include <iostream>
#include "../Task1/A.h"

// TASK 3: operators overloading

class Task3
{
public:
	void Start()
	{
		A a1(2, 3);
		A a2(1, 2);
		A a3;
		A a4[2];

		a4[0] = a1; a4[1] = a2;
		a3 = a2;
		a3 += a1;
		a3++;
		++a3;
		a3 = a1 + a2;
		a3 = a1 - a2;
		bool result = a1 > a2;
		result = a1 < a2;
		result = a1 == a2;
		result = a1 != a2;
		a3(1);
		a3(1, 2);
		a3 = a4[0];
	}
};
