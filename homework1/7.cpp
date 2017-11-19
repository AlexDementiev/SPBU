#include <iostream>

using namespace std;

void primeNumber(int x, int w){
    int numbers[w] = {0};
    int counter = 0;

    while (counter < w) {
        numbers[counter] = counter + 2;
        counter++;
    }

    counter = 2;
    while (counter < w / 2) {
        int j = counter * 2 - 2;
        while (j < w) {
            numbers[j] = 0;
            j += counter;
        }
        counter++;
    }

    int i = 0;
    while (numbers[i] <= x) {
        if (numbers[i]) {
            cout << numbers[i] << " ";
        }
        i++;
    }
}
int main()
{
    int lenght = 100;
    cout << "Enter n < " << lenght + 1 << " : ";

    int n = 0;
    cin >> n;

    primeNumber(n, lenght);
    return 0;
}
