#include <iostream>
#include <fstream>
#include <string.h>
#include "huffman.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.good())
    {
        cout << "error don't open file";
        return 1;
    }

    char* string = new char[maxSize]{};
    char* temp = new char[maxSize]{};

    while (!fin.eof())
    {
        fin.getline(temp, maxSize, '\n');
        strcat(string, temp);
        strcat(string, "\n");
    }
    fin.getline(temp, maxSize, '\n');
    strcat(string, temp);
    strcat(string, "\n");
    string[strlen(string) - 2] = '\0';

    huffmanEncode(string, fout);

    fin.close();
    fout.close();
    delete [] string;
    delete [] temp;
    return 0;
}
