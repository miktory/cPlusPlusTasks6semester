#include "ex3.h"
using namespace std;

// Задание 4_1
namespace ex3
{
    char* deleteFirstOccurrence(const char* str, const char symbol)
    {
        char* answer = new char[strlen(str)+1];
        bool skipped = false;
        int index = 0;
        for (int i = 0; i < strlen(str)+1; i++)
        {
            if (!skipped && str[i] == symbol)
            {
                skipped = true;
                continue;
            }
            answer[index] = str[i];
            index++;
        }
        return answer;
    }

    size_t strlen(const char* str) {
        size_t length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }
}

