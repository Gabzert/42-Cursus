#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m[i][j] = 0;
		}
	}
}

Matrix::Matrix(float m[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m[i][j] = m[i][j];
		}
	}
}

Matrix::Matrix(float v)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m[i][j] = (i == j) ? v : 0.0f;
		}
	}
}

Matrix::~Matrix()
{
}

Matrix Matrix::operator*(const Matrix &rhs)
{
	Matrix result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.m[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				result.m[i][j] += this->m[i][k] * rhs.m[k][j];
			}
		}
	}
	// std::cout << "Result: " << std::endl;
	// for  (int i = 0; i < 4; i++)
	// {
	// 	for (int j = 0; j < 4; j++)
	// 	{
	// 		std::cout << result.m[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	
	return result;

}