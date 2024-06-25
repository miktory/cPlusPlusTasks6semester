#include "ex1.h"

// Задание 3_1
namespace ex1
{
	const char* getSymbols(const char* str)
	{
        unsigned size = 5;
        unsigned index = 0;
		char* symbols = new char[size];
        bool foundStartBracket = false;
        for (const char* symbol = str; ; symbol++)
        {
            if (!foundStartBracket && *symbol == '(')
            {
                foundStartBracket = true;
                continue;
            }

            if (*symbol == ')')
                break;
            if (!foundStartBracket)
                continue;
            if (size < index+1)
            {
                symbols = resize(symbols, size, size * 2);
                size *= 2;
            }
            symbols[index] = *symbol;
            index++;
           if (*symbol == '\0')
                break;
        }
        if (symbols[index] == '\0')
            symbols = resize(symbols, size, 0);
        else
        {
            if (size < index + 1)
                symbols = resize(symbols, size, size+1);
            symbols[index] = '\0';
        }
        return symbols;
	}

    char* resize(const char* str, unsigned size, unsigned new_size)
    {
        char* newRegion = new char[new_size];
        int counter = 0;
        for (int i = 0; i < new_size && i < size; i++)
        {
            *newRegion = *str;
            if (i + 1 < new_size && i + 1 < size)
            {
                newRegion += 1;
                str += 1;
            }
            counter = i;
        }
        newRegion -= counter;
        str -= counter;
        delete[] str;
        return newRegion;
    }

}
