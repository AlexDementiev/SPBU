#include <iostream>

using namespace std;

int main()
{
    const int length = 28;
    const int value = 10;
    int r[length];

    for (int q = 0; q < length; ++q)
        r[q] = 0;

    for (int i = 0; i < value; ++i)
        for (int j = 0; j < value; ++j)
            for (int k = 0; k < value; ++k)
            {
                r[i + j + k]++;
            }

    int result = 0;

    for (int w = 0; w < length; ++w)
    {
        result += r[w] * r[w];
    }

    cout << "Happy tickets : " << result << endl;
    return 0;
}
