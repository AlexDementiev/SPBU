#include <iostream>
#include <fstream>

using namespace std;

void output(char *string, int position)
{
    while (string[position] != '\0')
    {
        cout << string[position];
        position++;
    }
    cout << endl;
}

void analysis(char* string, int size)
{
    int index = 0;
    while (index < size && string[index] != ';')
        index++;
    if (index != size)
        output(string, index);
}

void initString(char *string, int size)
{
    int counter = 0;
    while (counter < size)
    {
        string[counter] = '\0';
        counter++;
    }
}

int main()
{
    char *string = new char[256];
    initString(string, 256);

    ifstream input;
    input.open("input.txt");
    if (input.is_open())
    {
        while (input)
        {
            initString(string, 256);
            input >> string;
            if (string[0] == '\0')
                return 0;
            analysis(string, 256);
        }
    }
    return 0;
}
