#include <iostream>
#include <random>
#include "Matrix.h"

// TASK 5: class templates

int main()
{
	// random generator
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(0, 10);

	// matrices setup
	Matrix<int>* a = new Matrix<int>(5, 5);
	Matrix<int>* b = new Matrix<int>(5, 5);
	Matrix<int>* c = new Matrix<int>(5, 5);

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			a->setAt(i, j, distribution(generator));
			b->setAt(i, j, distribution(generator));
		}
	}

	// matrices sum
	a->print();
	b->print();
	std::cout << "a + b = " << std::endl;
	*c = *a + *b;
	c->print();

	// matrices multiplication
	std::cout << "a * b = " << std::endl;
	*c = *a * *b;
	c->print();

	delete a;
	delete b;
	delete c;

	return 0;
}
