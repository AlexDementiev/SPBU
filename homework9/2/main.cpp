#include <iostream>
#include <fstream>

#include "huffman.h"
#include "string.h"

using namespace std;

int main()
{
    ifstream input;
    input.open("input.txt");

    if (!input.is_open())
    {
        cout << "File not found\n";
        return 0;
    }

    String *string = inputString(input);
    input.close();

    HuffmanCode *huffmanCode = encode(string);

    ofstream output;
    output.open("output.txt");

    printHuffmanTree(huffmanCode, output);
    output << endl;

    for (int i = 0; i < stringLength(string); i++)
    {
        printString(getCode(huffmanCode, getChar(string, i)), output);
        output << " ";
    }

    printHuffmanCodes(huffmanCode, output);

    output.close();

    deleteHuffmanCode(huffmanCode);
    deleteString(string);
    return 0;

}
