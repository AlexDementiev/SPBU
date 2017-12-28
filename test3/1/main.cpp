#include <iostream>
#include <fstream>

using namespace std;

void reverse(char *number, ostream &output)
{
    int length = 0;
    while (number[length] != '\0')
        length++;

    length--;

    int index = 0;
    while (index <= length / 2)
    {
        int tmp = number[index];
        number[index] = number[length - index];
        number[length - index] = tmp;
        index++;
    }

    for (int i = 0; i <= length; i++)
        output << number[i];
    output << ' ';
}

int main()
{
    ifstream input;
    input.open("input.txt");
    if (!input.is_open())
    {
        cout << "File not found.";
        return 0;
    }

    ofstream output;
    output.open("output.txt");

    char buf[255] = {'\0'};
    while (input >> buf)
    {
        reverse(buf, output);
    }

    input.close();
    output.close();
    return 0;
}
