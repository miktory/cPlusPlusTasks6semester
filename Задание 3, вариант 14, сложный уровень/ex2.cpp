#include "ex2.h"

// Задание 3_2
namespace ex2
{
	int getShortestWordLength(const char* str)
	{
		int minLen = 0;
		int counter = 0;
		for (const char* symbol = str; ; symbol++)
		{
			if (isalpha(*symbol))
			{
				counter++;
				continue;
			}
			if (minLen == 0)
				minLen = counter;
			else if (minLen > counter && counter != 0)
				minLen = counter;
			counter = 0;
			if (*symbol == '\0')
				break;
		}
		return minLen;
	}

	int getLongestWordLength(const char* str)
	{
		int maxLen = 0;
		int counter = 0;
		for (const char* symbol = str; ; symbol++)
		{
			if (isalpha(*symbol))
			{
				counter++;
				continue;
			}
			if (maxLen == 0)
				maxLen = counter;
			else if (maxLen < counter && counter != 0)
				maxLen = counter;
			counter = 0;
			if (*symbol == '\0')
				break;
		}
		return maxLen;
	}
}
