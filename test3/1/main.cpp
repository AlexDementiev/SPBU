#include <iostream>

using namespace std;

void quikSort(int numbers[], int left, int right) {
    int l = left;
    int r = right;
    int line = numbers[(left + right) / 2];

    while (l < r){

        while (numbers[l] < line) {
            l++;
        }
        while (numbers[r] > line) {
            r--;
        }
        if (l <= r) {
            int tmp = numbers[l];
            numbers[l] =  numbers[r];
            numbers[r] = tmp;
            l++;
            r--;
        }

        if (l < right)
            quikSort(numbers, l, right);
        if (r > left)
            quikSort(numbers, left, r);
    }
}

int main()
{
    int const size = 100;
    int *numbers = new int[size];

    int counter = 0;
    while (counter < size)
    {
        numbers[counter] = 0;
        counter++;
    }

    cout << "Enter numbers: ";

    int digit = 0;
    counter = 0;
    cin >> digit;
    while (digit != 0)
    {
        numbers[counter] = digit;
        counter++;
        cin >> digit;
    }

    quikSort(numbers, 0, counter);

    int dimension = counter;
    counter = 1;
    while (counter <= dimension)
    {
        cout << numbers[counter] << ": ";
        int value = numbers[counter];
        counter++;

        int count = 1;
        while (numbers[counter] == value)
        {
            count++;
            counter++;
        }

        cout << count << ";\n";
    }
    return 0;
}
