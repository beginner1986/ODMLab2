#pragma once

template <class T>
class Matrix
{
private:
	size_t m, n;
	T* content;

public:
	Matrix(size_t _m, size_t _n) : m(_m), n(_n)	{ content = new T[m * n]; }
	~Matrix() { delete content; }

	size_t getM() const { return m; }
	size_t getN() const { return n; }
	T getAt(size_t i, size_t j) const { return content[i * m + j]; }

	void setAt(size_t i, size_t j, T value)	{ content[i * m + j] = value; }

	Matrix& operator+(const Matrix& other)
	{
		Matrix *result = new Matrix(m, n);

		if (this->m != other.m || this->n != other.n)
		{
			std::cout << "Matrices must have equal sizes!" << std::endl;
			exit(0);
		}
		else
		{
			for (size_t i = 0; i < m; i++)
			{
				for (size_t j = 0; j < n; j++)
				{
					T value = this->getAt(i, j);
					value += other.getAt(i, j);
					result->setAt(i, j, value);
				}
			}
		}

		return *result;
	}

	Matrix& operator*(const Matrix& other)
	{
		if (this->n != other.m)
		{
			std::cout << "Cannot multiply! Incorrect matricirs sizes." << std::endl;
			exit(0);
		}
		
		Matrix *result = new Matrix(m, n);

		for (size_t i = 0; i < other.getN(); i++)
		{
			for (size_t j = 0; j < this->m; j++)
			{
				T temp = 0;
				for (size_t k = 0; k < other.getN(); k++)
				{
					temp = temp + this->getAt(i, k) * other.getAt(k, j);
				}
				result->setAt(i, j, temp);
			}
		}

		return *result;
	}

	void print()
	{
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				std::cout << content[i * m + j] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}
};
