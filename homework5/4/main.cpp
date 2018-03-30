#include <iostream>
#include <fstream>

using namespace std;

bool isEmpty(char string[])
{
    int index = 0;
    while (string[index] != '\0')
    {
        switch (string[index])
        {
            case ' ' :
                index++; break;
            case '\t' :
                index++; break;
            default :
                return false; break;
        }
    }

    return true;
}

int main()
{
    char string[255];
    ifstream fin("input.txt");

   int counter = 0;
    while (fin)
    {
        fin.getline(string, 255, '\n');

        if (!isEmpty(string))
            counter++;
    }

    cout << counter - 1;
    fin.close();

    return 0;
}
