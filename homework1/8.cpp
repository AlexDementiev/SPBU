#include <iostream>

using namespace std;

int factorialRecursive(int x)
{
    if (x == 1)
        return 1;
    else
        return x * factorialRecursive(x - 1);
}

int factorialIterative(int r)
{
    int f = 1;

    for (int i = 1; i <= r; ++i)
    {
        f *= i;
    }

    return f;
}

int main()
{
    int n = 0;

    cout << "Type n : ";
    cin >> n;

    int recursiveFactorial = factorialRecursive(n);
    int iterativeFactorial = factorialIterative(n);

    cout << "n! : " << recursiveFactorial << endl;
    cout << "n! : " << iterativeFactorial << endl;
    return 0;
}
