#include <iostream>
#include "ex1.h"
#include "ex2.h"
#include "ex3.h"




int main()
{
    std::setlocale(LC_ALL, "Russian");
    // Вариант 14, Межин Матвей, Задание 3, высокий уровень (файлы 3_1, 3_2, 4_1)
    // Задание 3_1
    std::cout << "Номер 3_1" << std::endl;
    const char* str = "test (string 1234) test";
    const char* result = ex1::getSymbols(str);
    std::cout << "Входная строка: " << str << std::endl;
    std::cout << "Результат: " << result << std::endl; // OUTPUT: Результат: string 1234
    delete[] result;
    str = "_1243sdf(test   test)       wegwegf";
    result = ex1::getSymbols(str);
    std::cout << "Входная строка: " << str << std::endl;
    std::cout << "Результат: " << result << std::endl; // OUTPUT: Результат: test   test
    std::cout << std::endl;
    delete[] result;

    // Задание 3_2
    const int maxLen = 2048;
    char* tmp = new char[maxLen];
    std::cout << "Номер 3_2" << std::endl;
    std::cout << "Введите текст: ";
    std::cin.getline(tmp, maxLen);
    // Пример: INPUT: Should. I. Do. This?
    // OUTPUT: Str: "Should. I. Do. This?" Min word len: 1 Max word len: 6
    std::cout << "Str: " << "\"" << tmp << "\""  << " Min word len: " << ex2::getShortestWordLength(tmp) << " Max word len: " << ex2::getLongestWordLength(tmp) << std::endl;
    std::cout << std::endl;

    // Задание 4_1
    // У 14 варианта ошибка в условии - не указано, первое вхождение какого символа нужно удалить. Поэтому я написал функцию, удаляющую
    // первое вхождение заданного символа.
    std::cout << "Номер 4_1" << std::endl;
    const char* input = "This string contais a lot of symbols";
    char* output = ex3::deleteFirstOccurrence(input, 'g');
    std::cout << "Input str: " << "\"" << input << "\"" << " Output str: " << "\"" << output << "\"" << std::endl;
    delete[] output;


}
