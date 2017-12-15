#include <iostream>


using namespace std;


void input(int *numbers, int size)
{
    cout << "Enter numbers: ";
    for (int i = 0; i < size; i++)
    {
        int digit  = 0;
        cin >> digit;
        numbers[i] = digit;
    }
}

void createArray(int **numbers, int size)
{
    int counter = 0;
    while (counter < size)
    {
        numbers[counter] = new int[size]{0};
        counter++;
    }
}

int minElement(int *digits, int size)
{
    int min = digits[0];
    int counter = 1;
    while (counter < size)
    {
        if (digits[counter] < min)
            min = digits[counter];
        counter++;
    }

    return min;
}

bool isMax(int *digits, int size, int value)
{
    int counter = 0;
    while (counter < size)
    {
        if (digits[counter] > value)
            return false;
        counter++;
    }

    return true;
}

int main()
{
    int size = 0;
    cout << "Enter dimension (n*n): ";
    cin >> size;

    int **numbers = new int*[size];
    createArray(numbers, size);

    int index = 0;
    while (index < size)
    {
        input(numbers[index], size);
        index++;
    }

    int counter = 0;
    while (counter < size)
    {
        int min = minElement(numbers[counter], size);
        int position = 0;
        while (position < size)
        {
            if(numbers[counter][position] == min)
            {
                int *digits = new int[size];
                int index = 0;
                while (index < size)
                {
                    digits[index] = numbers[index][position];
                    index++;
                }
                if (isMax(digits, size, min))
                    cout << "(" << counter + 1 << ", " << position + 1 << "): " << min << endl;
            }
            position++;
        }
        counter++;
    }

    return 0;
}
