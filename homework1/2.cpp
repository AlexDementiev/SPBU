#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");

    int n = 0;
    int k = 0;

    cout << "Enter the dividend : ";
    cin >> n;

    cout << "Enter the divisor : ";
    cin >> k;

    int c = 0;
    bool p = false;
    if (n * k < 0) {
        p = true;
    }
    if (n < 0)
        n = -n;
    if (k < 0)
        k = -k;

    while (n >= k)
    {
        c++;
        n = n-k;
    }

    if (p)
        c = -c;

    cout << "Partial private : " << c << endl;
    return 0;
}
