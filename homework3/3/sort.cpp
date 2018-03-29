#include "sort.h"

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
