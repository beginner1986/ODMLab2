#include <iostream>
#include <tbb/tbb.h>

#include "Matrix.h"

// TBB6: tbb::parallel_for

void sequenceMultiply(const Matrix& A, const Matrix& B, Matrix& result);
void parallelMultiply(const Matrix& A, const Matrix& B, Matrix& result);

int main()
{
	// setup
	std::cout << "Reading matrix A..." << std::endl;
	Matrix* A = new Matrix("A");
	std::cout << "Reading matrix B..." << std::endl;
	Matrix* B = new Matrix("B");
	std::cout << "Creating matrix Csequence and Cparallel..." << std::endl;
	Matrix* Csequence = new Matrix(A->getN(), B->getM());
	Matrix* Cparallel = new Matrix(A->getN(), B->getM());

	//sequence
	std::cout << "sequence multiplication" << std::endl;
	tbb::tick_count before = tbb::tick_count::now();
	sequenceMultiply(*A, *B, *Csequence);
	tbb::tick_count after = tbb::tick_count::now();
	std::cout << "DONE. Time: " << (after - before).seconds() << "s" << std::endl;
	std::cout << "Saving Csequence matrix to file..." << std::endl;
	Csequence->writeToFile("Csequence");
	delete Csequence;

	// tbb::parallel_for
	std::cout << "tbb::parallel_for multiplication" << std::endl;
	before = tbb::tick_count::now();
	parallelMultiply(*A, *B, *Cparallel);
	after = tbb::tick_count::now();
	std::cout << "DONE. Time: " << (after - before).seconds() << "s" << std::endl;
	std::cout << "Saving Cparallel matrix to file..." << std::endl;
	Cparallel->writeToFile("Cparallel");

	// clean the mess
	delete A, B, Cparallel;
	std::cout << "All done." << std::endl;

	return 0;
}

void sequenceMultiply(const Matrix& A, const Matrix& B, Matrix& result)
{
	// check multiplication correctness condition
	if (A.getN() != B.getM())
	{
		std::cout << "Cannot multiply the matrices!" << std::endl;
		exit(-1);
	}

	// perform the multiplication
	for (int i = 0; i < A.getM(); i++)
	{
		for (int j = 0; j < B.getN(); j++)
		{
			float temp = 0;
			for (int k = 0; k < A.getN(); k++)
			{
				temp = temp + A.getAt(i, k) * B.getAt(k, j);
			}
			result.setAt(i, j, temp);
		}
	}
}

void parallelMultiply(const Matrix& A, const Matrix& B, Matrix& result) {
	// check multiplication correctness condition
	if (A.getN() != B.getM())
	{
		std::cout << "Cannot multiply the matrices!" << std::endl;
		exit(-1);
	}

	// perform the multiplication
	tbb::parallel_for(0, A.getM(), [&](int i) {
		for (int j = 0; j < B.getN(); j++)
		{
			float temp = 0;
			for (int k = 0; k < A.getN(); k++)
			{
				temp = temp + A.getAt(i, k) * B.getAt(k, j);
			}
			result.setAt(i, j, temp);
		}
	});
}