#include <iostream>

// TASK 4: function templates

template<typename T>
void findElement(T *array, size_t size, T element)
{
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] == element)
			std::cout << i << " ";
	}
	std::cout << std::endl;
}

void findElement(char* array, size_t size, char element)
{
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] == element)
			std::cout << i << ": " << array[i] << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "Template for int array:" << std::endl;
	int intArray[] = { 1, 2, 3, 4, 3, 2, 1 };
	findElement(intArray, 7, 2);

	std::cout << std::endl << "Template for unsigned long long array:" << std::endl;
	unsigned long long ullArray[] = { 312312, 0, 1, 2, 312312, 1 };
	findElement(ullArray, 6, (unsigned long long)312312);

	std::cout << std::endl << "Template overloaded for char array:" << std::endl;
	char charArray[] = { 'a', 'b', 'c', 'd', 'b', 'a' };
	findElement(charArray, 6, 'b');

	return 0;
}
