#include <iostream>
#include <fstream>
#include <cstring>
#include <fstream>
#include "huffman.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.good())
    {
        cout << "No input file";
        return 1;
    }

    huffmanDecode(fin, fout);

    fin.close();
    fout.close();
    return 0;
}
