#include <iostream>

using namespace std;

int input() {
    int z = 0;
    cin >> z;
    return z;
}

int fibonacciRecursive(int x) {
    if (x <= 2) {
        return 1;
    }
    return fibonacciRecursive(x - 1) + fibonacciRecursive(x - 2);
}

int fibonacciIterative(int c) {
    int a = 1;
    int b = 1;
    int result = 1;
    int i = 3;

    while (i <= c) {
        result = a + b;
        a = b;
        b = result;
        i++;
    }
    return result;
}

void output(int h) {
    cout << h << endl;
}

int main()
{
    int number = 0;

    cout << "Enter the number Fibonacci numbers : " ;
    number = input();

    int res1 = fibonacciRecursive(number);

    cout << "Fibonacci number " << number << " (recursive algorithm) : ";
    output(res1);

    int res2 = fibonacciIterative(number);

    cout << "Fibonacci number " << number << " (iterative algorithm) : ";
    output (res2);
    return 0;
}
