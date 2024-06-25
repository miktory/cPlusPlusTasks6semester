#include "ex1.h"

namespace ex1
{
	void sortByDescending(int* arr, size_t arrSize)
	{
        for (int i = 0; i < arrSize - 1; i++)
        {
            for (int j = 0; j < arrSize - i - 1; j++)
            {
                if (binaryToDecimal(arr[j]) < binaryToDecimal(arr[j + 1])) 
                    std::swap(arr[j], arr[j + 1]);
            }
        }
	}

    int sum(int* arr, size_t arrSize)
    {
        int res = 0;
        for (size_t i = 0; i < arrSize; i++)
            res += binaryToDecimal(arr[i]);
        return res;
    }

    int binaryToDecimal(int binary) {
        int decimal = 0;
        int base = 1;

        while (binary != 0) {
            int digit = binary % 10;
            decimal += digit * base;
            base *= 2;
            binary /= 10;
        }
        return decimal;
    }
}
