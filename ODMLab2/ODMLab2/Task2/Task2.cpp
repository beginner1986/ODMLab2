// TASK 2: polymorphism

#include "Final.h"

class Task2
{
public:
	void Start()
	{
		Middle* middle = new Middle();
		middle->Hello();
		middle->Bye();
		middle->FinalFunction();

		Final* final = new Final();
		final->Hello();
		final->Bye();

		Abstract* abstract = new Final();
		abstract->Hello();

		delete middle;
		delete final;
		delete abstract;
	}
};