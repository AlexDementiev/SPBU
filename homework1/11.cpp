#include <iostream>

using namespace std;

void input(int numbers[], int arraySize) {
    int counter = 0;
    while(counter < arraySize){
        cin >> numbers[counter];
        counter++;
    }
}

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
            swap(numbers[l], numbers[r]);
            l++;
            r--;
        }

        if (l < right)
            quikSort(numbers, l, right);
        if (r > left)
            quikSort(numbers, left, r);
    }
}

void output(int numbers[], int arraySize) {
    int t = 0;
    while (t < arraySize) {
        cout << numbers[t] << " ";
        t++;
    }
}

int main()
{
    const int n = 10;
    int a[n] = {0};

    cout << "Enter an array of 10 characters : " << endl;
    input(a, n);

    quikSort(a, 0, n-1);

    cout << "the sorted array : ";
    output(a, n);

    return 0;
}
