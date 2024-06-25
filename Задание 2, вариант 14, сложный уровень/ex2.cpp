#include "ex2.h"

namespace ex2
{
    int** createMatrix(size_t rows, size_t columns)
    {
        int** matrix = new int* [rows];
        for (size_t i = 0; i < rows; i++)
            matrix[i] = new int[columns];
        return matrix;
    }

    void deleteMatrix(int** matrix, size_t rows, size_t columns)
    {
        for (size_t i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    void moveMinElementsToFirstColumn(int** matrix, size_t rows, size_t columns)
    {
        for (size_t i = 0; i < rows; i++)
        {
            int* minEl = &matrix[i][0];
            for (size_t j = 0; j < columns; j++)
            {
                if (matrix[i][j] < *minEl)
                    minEl = &(matrix[i][j]);
                if (j == columns - 1)
                    std::swap(matrix[i][0], *minEl);
            }
        }
    }
}
