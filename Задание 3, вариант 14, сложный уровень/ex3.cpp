#include "ex3.h"
using namespace std;

// Задание 4_1
namespace ex3
{
    const string deleteFirstOccurrence(string str, const char symbol)
    {
        string answer;
        bool skipped = false;
        for (int i = 0; i < str.length(); i++)
        {
            if (!skipped && str[i] == symbol)
            {
                skipped = true;
                continue;
            }
            answer.append(1, str[i]);
        }
        return answer;
    }
}

