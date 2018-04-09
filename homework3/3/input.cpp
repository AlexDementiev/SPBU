#include <iostream>
#include "input.h"

using namespace std;

void input(long int *a) {
    cin >> *a;
}

int inputString(char *number) {
    char current = ' ';
    cin >> current;
    int index = 0;
    while (current != '\n') {
        number[index] = current;
        index++;
        current = cin.get();
    }

    return index;
}

