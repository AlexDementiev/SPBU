#include <cstdlib>
#include <ctime>
#include "core.h"

int *getNumber()
{
    srand((unsigned int) time(nullptr));
    int digits[10];
    for (int i = 0; i < 10; i++)
        digits[i] = i;

    int *number = new int[numberOfDigits];
    for (int i = 0; i < numberOfDigits; i++)
        number[i] = 0;

    int currentDigit = (rand() % 9) + 1; //cant be a zero
    for (int i = 0; i < numberOfDigits; i++)
    {
        number[i] = digits[currentDigit];
        for (int j = currentDigit; j < 9 - i; j++)
            digits[j] = digits[j + 1];
        currentDigit = rand() % (9 - i);
    }
    return number;
}

int *charToInt(const char *charArray)
{
    int *intArray = new int[4];
    for (int i = 0; i < numberOfDigits; i++)
    {
        intArray[i] = ((int) charArray[i]) - ((char) '0');
    }
    return intArray;
}

int numberOfBulls(const char *attempt, const int *answer)
{
    int *intAttempt = charToInt(attempt);
    int result = 0;
    for (int i = 0; i < numberOfDigits; i++)
    {
        if (intAttempt[i] == answer[i])
            result++;
    }
    delete[] intAttempt;
    return result;
}

int numberOfCows(const char *attempt, const int *answer)
{
    int *intAttempt = charToInt(attempt);
    int result = 0;
    for (int i = 0; i < numberOfDigits; i++)
    {
        for (int j = 0; j < numberOfDigits; j++)
        {
            if ((i != j) && (intAttempt[i] == answer[j]))
                result++;
        }
    }
    delete[] intAttempt;
    return result;
}

bool isCorrect(const char *attempt)
{
    int length = 0;
    while (attempt[length] != '\0')
        length++;

    if (length != numberOfDigits)
        return false;

    for (int i = 0; i < numberOfDigits; i++)
    {
        if ((attempt[i] < '0') || (attempt[i] > '9'))
            return false;
    }

    for (int i = 0; i < numberOfDigits - 1; i++)
        for (int j = i + 1; j < numberOfDigits; j++)
            if (attempt[i] == attempt[j])
                return false;

    return true;
}
