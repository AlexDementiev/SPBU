#include <iostream>
#include <fstream>

#include "string.h"

using namespace std;



int hashFunction(String *string, int mod)
{
    int const prime = 17;

    int result = 0;
    int power = 1;

    for (int i = 1; i < stringLength(string); i++)
    {
        result = (result + (power * (int) getChar(string, i)) % mod) % mod;
        power = (power * prime) % mod;
    }

    return result;
}

void searchPattern(String *string, String *pattern)
{
    int bigPrime = 10601;
    int size = stringLength(pattern);
    int length = stringLength(string);
    int *result = new int[length - size + 1]{-1};
    for (int i = 0; i < length - size + 1; i++)
    {
        String *currentPart = subString(string, i, i + size - 1);
        result[i] = hashFunction(currentPart, bigPrime);
        deleteString(currentPart);
    }

    int imprint = hashFunction(pattern, bigPrime);
    for (int i = 0; i < length - size + 1; i++)
    {
        if (result[i] == imprint)
        {
            String *current = subString(string, i, i + size - 1);
            if (isEqual(pattern, current))
                cout << i + 1 << " ";
            deleteString(current);
        }
    }
    delete[] result;
}

int main()
{
    ifstream inputFile;
    inputFile.open("input.txt");
    if (!inputFile.is_open())
    {
        cout << "file not found\n";
        return 0;
    }

    String *string = inputString(inputFile);
    String *pattern = inputString(inputFile);

    inputFile.close();


    cout << "String: ";
    printString(string, cout);
    cout << endl;

    cout << "Pattern: ";
    printString(pattern, cout);
    cout << endl;

    cout << "Indices of occurrences: ";
    searchPattern(string, pattern);

    deleteString(string);
    deleteString(pattern);

    return 0;
}
