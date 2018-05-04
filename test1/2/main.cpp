#include <iostream>

using namespace std;

void input(bool *array, int size)
{
    cout << "Enter numbers 0,1: ";
    int index = 0;
    while (index < size)
    {
        cin >> array[index];
        index++;
    }
}

int isLarger(bool *firstNumber, bool *secondNumber, int size)
{
    int counter = 0;
    while (counter < size && firstNumber[counter] && secondNumber[counter])
        counter++;

    if (counter == size)
        return 3;

    if (firstNumber[counter] && !secondNumber[counter])
        return 1;

    if (!firstNumber[counter] && secondNumber[counter])
        return 2;
}

int main()
{
    cout << "Enter array size: ";
    int size = 0;
    cin >> size;

    bool *firstNumber = new bool[size]{false};
    input(firstNumber, size);

    cout << "Enter array size: ";
    int dimension = 0;
    cin >> dimension;

    bool *secondNumber = new bool[dimension]{false};
    input(secondNumber, dimension);

    if (size < dimension)
    {
        cout << "The second number is greater than the first\n";
        return 0;
    }
    if (size > dimension)
    {
        cout << "The first number is greater than the second\n";
        return 0;
    }

    switch (isLarger(firstNumber, secondNumber, size))
    {
    case 1:
        cout << "The first number is greater than the second\n";
        break;
    case 2:
        cout << "The second number is greater than the first\n";
        break;
    case 3:
        cout << "Equal numbers\n";
    }
    return 0;
}
