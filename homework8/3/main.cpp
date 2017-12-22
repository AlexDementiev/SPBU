#include <iostream>
#include <fstream>

#include "hashtable.h"
#include "string.h"

using namespace std;

bool isSeparator(char symbol)
{
    return symbol == '\n' || symbol == '\0' || symbol == ' ' ||
           symbol == ','  || symbol == '?'  || symbol == '!' ||
           symbol == ':'  || symbol == ';'  || symbol == '.';
}

void addWords(HashTable *table, String *string)
{
    int beginWord = 0;
    int endWord = 0;
    int currentIndex = 0;
    while (currentIndex < stringLength(string))
    {
        currentIndex = endWord;
        while (currentIndex < stringLength(string) && isSeparator(getChar(string, currentIndex)))
            currentIndex++;
        beginWord = currentIndex;

        while (currentIndex < stringLength(string) && !isSeparator(getChar(string, currentIndex)))
            currentIndex++;
        endWord = currentIndex;

        if (beginWord < endWord)
            add(table, subString(string, beginWord, endWord - 1));
    }
    deleteString(string);
}

int main()
{
    ifstream inputFile;
    inputFile.open("input.txt");

    if (!inputFile.is_open())
    {
        cout << "File not found" << endl;
        return 0;
    }

    HashTable *hashTable = createTable();

    while (!inputFile.eof())
    {
        String *newLine = inputString(inputFile);
        addWords(hashTable, newLine);
    }
    inputFile.close();

    cout << "Word and their frequencies: " << endl;
    printElements(hashTable, cout);
    cout << "Load faktor: " << loadFactor(hashTable) << endl;
    cout << "Maxsimal spreadsheet cell: \n";
    printMaxSpreadsheet(hashTable, cout);
    cout << "Number of added words: " << numberOfWords(hashTable) << endl;
    cout << "Number of empty cells: " << numberOfEmptyCells(hashTable) << endl;

    deleteTable(hashTable);

    return 0;
}
