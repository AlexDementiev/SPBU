#include <iostream>

using namespace std;

int main()
{
    int64_t x = 0;

    cout << "Type x : ";
    cin >> x;

    int sqr = x * x;
    int64_t result = (sqr + 1) * (sqr + 1) + 1;

    cout << "x^4 + x^3 + x^2 + x + 1 = " << result << endl;
    return 0;
}
