#include "Final.h"

// TASK 2: polymorphism

int main()
{
	std::cout << "new Middle" << std::endl;
	Middle* middle = new Middle();
	std::cout << std::endl << "middle->Hello()" << std::endl;
	middle->Hello();
	std::cout << std::endl << "middle->Bye()" << std::endl;
	middle->Bye();
	std::cout << std::endl << "middle->FinalFunction()" << std::endl;
	middle->FinalFunction();

	std::cout << std::endl << "new Final" << std::endl;
	Final* final = new Final();
	std::cout << std::endl << "final->Hello()" << std::endl;
	final->Hello();
	std::cout << std::endl << "final->Bye()" << std::endl;
	final->Bye();

	std::cout << std::endl << "Abstract* abstract = new Final()" << std::endl;
	Abstract* abstract = new Final();
	std::cout << std::endl << "abstract->Hello()" << std::endl;
	abstract->Hello();

	std::cout << std::endl << "delete Middle" << std::endl;
	delete middle;
	std::cout << std::endl << "delete Final" << std::endl;
	delete final;
	std::cout << std::endl << "delete Abstract (Final)" << std::endl;
	delete abstract;

	return 0;
}
