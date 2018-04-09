#include "small.h"
#include "sort.h"
#include <iostream>

using namespace std;

void transfer(int *digits, char *number, int dimension) {
    int counter = 0;
    while (counter < dimension) {
        digits[counter] = number[counter] - '0';
        counter++;
    }
}

void output(int *numbers, int size) {
    cout << "the smallest number: ";
    int index = 0;
    while (numbers[index] < 10 && index < size) {
        cout << numbers[index];
        index++;
    }
    cout << endl;
}

void smallestNumber(char *number, int size) {
    int dimension = 100;
    int digits[dimension];

    for (int i = 0; i < dimension; i++)
        digits[i] = 10;

    transfer(digits, number, size);

    quikSort(digits, 0, size);

    if (digits[0] == 0) {
        int i = 1;
        while (digits[i] == 0) {
            i++;
        }
        int tmp = digits[i];
        digits[i] = digits[0];
        digits[0] = tmp;
    }

    output(digits, size);
}
