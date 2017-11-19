#include <iostream>

using namespace std;

void turnover(int a[], int start, int length)
{
    int l = start - 1;
    int r = start + length - 2;

    while (l < r)
    {
        swap(a[l],a[r]);
        l++;
        r--;
    }
}

int main()
{
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m = 0;
    int n = 0;

    cout << "Type length m : ";
    cin >> m;

    cout << "Type length n : ";
    cin >> n;

    turnover(numbers, 1, m);
    turnover(numbers, m + 1, n);
    turnover(numbers, 1, m + n);

    for (int i = 0; i < m + n; ++i)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}
