#include <iostream>

using namespace std;

int power(int base, int index)
{
    if (index == 1)
        return base;
    else
        return (base * power(base, index - 1));
}

int main()
{
    int a = 0;
    int n = 0;

    cout << "Type a : ";
    cin >> a;

    cout << "Type n : ";
    cin >> n;

    int result = power(a, n);

    cout << "a^n = " << result << endl;
    return 0;
}
