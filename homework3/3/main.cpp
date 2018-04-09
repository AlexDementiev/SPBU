#include <iostream>
#include "small.h"
#include "input.h"

using namespace std;

int main()
{
    cout << "Enter the number : ";
    char *number = new char[100];

    int size = inputString(number);
    smallestNumber(number, size);

    delete[] number;
    return 0;
}
