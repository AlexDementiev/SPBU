#include <iostream>
#include <fstream>

#include "huffman.h"


using namespace std;

int main()
{
    ifstream inputFile;
    inputFile.open("input.txt");

    if (!inputFile.is_open())
    {
        cout << "File not found.\n";
        return 0;
    }

    decode(inputFile, cout);
    inputFile.close();
    return 0;
}
