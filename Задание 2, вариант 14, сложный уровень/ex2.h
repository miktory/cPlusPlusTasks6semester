#pragma once
#include<iostream>
namespace ex2
{
	int** createMatrix(size_t rows, size_t columns);
	void deleteMatrix(int** matrix, size_t rows, size_t columns);
	void moveMinElementsToFirstColumn(int** matrix, size_t rows, size_t columns);
}
