#include <iostream>
#include <string>
#include "ex1.h"
#include "ex2.h"

void printArr(int* arr, size_t size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << "(" << ex1::binaryToDecimal(arr[i]) << ")" << " ";
    std::cout << std::endl;
}

void printMatrix(int** matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

void fillMatrix(int** matrix, size_t rows, size_t columns)
{
    std::cout << "Размер матрицы: " << rows << "x" << columns << std::endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            std::cout << "Введите [" << i << "][" << j << "] элемент матрицы: ";
            std::cin >> matrix[i][j];
        }
    }
    std::cout << std::endl;
}

void fillArr(int* arr, size_t size) // 
{
    std::cout << "Вместительность массива: " << size << " элемент(-а/-ов)" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Введите " << i <<  " элемент массива: ";
        std::cin >> arr[i];
    }
    std::cout << std::endl;
}

// В требованиях указано: все операции вода и вывода произвоить в main, соответственно, дополнительные функции для ввода/вывода находятся тут,
// а не в ex1 и ex2. Все необходимые операции реализованы в соответствующих модулях, как и требовалось. В первом задании сделано аналогично.

int main()
{
    // Вариант 14, Межин Матвей, Задание 2, высокий уровень (файлы 1_2, 2.2)
    std::setlocale(LC_ALL, "Russian");
    // Числа записываем обязательно без незначащих нулей! Иначе число будет воспринято как HEX. 
    // Пример записи:  0, 10, 1, 11, 10, 111, 110, 111
    int arrSize = 0;
    std::cout << "Упражнение 1 " << std::endl;
    std::cout << "Введите размер массива: ";
    std::cin >> arrSize;
    int* arr = new int[arrSize];
    fillArr(arr, arrSize);
    std::cout << "Изначальный массив: " << " ";
    printArr(arr, arrSize);
    ex1::sortByDescending(arr, arrSize);
    std::cout << "Отсортированный массив: " << " ";
    printArr(arr, arrSize);
    std::cout << "Cумма: " << " " << ex1::sum(arr, arrSize) << std::endl;
    delete[] arr;
    std::cout << "--------------------------" << std::endl;


    std::cout << "Упражнение 2 " << std::endl;
    // Для матрицы:
    // 4 2 2
    // 3 0 1
    // 9 4 3
    // Результат должен быть:
    // 2 4 2
    // 0 3 1
    // 3 4 9
    int rows = 0;
    int cols = 0;
    std::cout << "Введите количество строк матрицы: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов матрицы: ";
    std::cin >> cols;
    int** matrix = ex2::createMatrix(rows, cols);
    fillMatrix(matrix, rows, cols);
    std::cout << "Матрица до преобразований: " << std::endl;
    printMatrix(matrix, rows, cols);
    std::cout << "Матрица после преобразований: " << std::endl;
    ex2::moveMinElementsToFirstColumn(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
    ex2::deleteMatrix(matrix, rows, cols);
}