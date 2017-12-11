#include <iostream>

using namespace std;

void input(int numbers[])
{
    cout << "Enter a when the input is finished" << endl;

    int index = 0;
    int value = 0;
    int counter = 0;
    while (cin >> index >> value)
    {
        numbers[index - 1] = value;
        counter++;
    }
}

void updateValue(int *numbers, int size)
{
    int value = 0;
    int counter = 3;
    while (counter < size)
    {
        value = numbers[counter];
        while (value > 3 && value != 0)
            value = numbers[value - 1];
        numbers[counter] = value;
        counter++;
    }
}

void output(int *numbers, int size)
{
    int counter = 0;
    while (counter < size)
    {
        if (numbers[counter])
            cout << "Student: " << counter + 1 << " Variant number: " << numbers[counter] << endl;
        else
            cout << "Student: " << counter + 1 << " did not pass the job" << endl;
        counter++;
    }
}

int main()
{
    int size = 0;
    cout << "Enter size: ";
    cin >> size;

    int *students = new int[size]{0};

    input(students);
    updateValue(students, size);
    output(students, size);

    return 0;
}
