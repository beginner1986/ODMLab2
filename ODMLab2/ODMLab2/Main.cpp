#include <iostream>
#include "D.h"

int main()
{
	// zadanie 1
	A* a = new A(1, 2);
	B* b = new B(2, 4, 6, 8);
	C* c = new C(3, 6, 9, 12, 15, 18);
	D* d = new D(1, 2, 3, 4, 5, 6, 7, 8);

	delete a;
	delete b;
	delete c;
	delete d;
}
