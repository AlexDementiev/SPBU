#include <iostream>

using namespace std;

int input() {
    int z = 0;
    cin >> z;
    return z;
}

int binpow(int x, int p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 1) {
        return binpow(x, p - 1) * x;
    }
    else {
        int b = binpow(x, p / 2);
        return b * b;
    }
}

void output(int s) {
    cout << s << endl;
}

int main()
{
    cout << "Enter the base of power : ";
    int base = input();

    cout << "Enter the exponent : ";
    int exponent = input();

    int result = binpow(base, exponent);

    cout << "a^n is ";
    output(result);

    return 0;
}
