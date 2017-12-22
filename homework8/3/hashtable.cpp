#include "hashtable.h"

struct TableElement
{
    String *string;
    int count;
    TableElement *nextElement;
};

struct HashTable
{
    int const size = 10601;
    TableElement **spreadsheet;
};

int hash(String *string, int mod)
{
    int const prime = 17;

    int result = 0;
    int power = 1;

    for (int i = 1; i < stringLength(string); i++)
    {
        result = (result + (power * (int) getChar(string, i)) % mod) % mod;
        power = (power * prime) % mod;
    }

    return result;
}

HashTable *createTable()
{
    HashTable *newTable = new HashTable;

    newTable->spreadsheet = new TableElement *[newTable->size];
    for (int i = 0; i < newTable->size; i++)
        newTable->spreadsheet[i] = nullptr;

    return newTable;
}

void deleteSpreadsheet(TableElement *element)
{
    if (element == nullptr)
        return;

    deleteSpreadsheet(element->nextElement);
    deleteString(element->string);
    delete element;
}

void deleteTable(HashTable *table)
{
    for (int i = 0; i < table->size; i++)
        deleteSpreadsheet(table->spreadsheet[i]);

    delete[] table->spreadsheet;
    delete table;
}

void add(HashTable *table, String *string)
{
    int index = hash(string, table->size);

    TableElement *tmp = table->spreadsheet[index];
    while (tmp != nullptr)
    {
        if (isEqual(tmp->string, string))
        {
            tmp->count++;
            return;
        }
        tmp = tmp->nextElement;
    }

    TableElement *newElement = new TableElement;
    newElement->count = 1;
    newElement->string = string;
    newElement->nextElement = table->spreadsheet[index];
    table->spreadsheet[index] = newElement;
}

bool contains(HashTable *table, String *string)
{
    int index = hash(string, table->size);

    TableElement *tmp = table->spreadsheet[index];
    while (tmp != nullptr)
    {
        if (isEqual(tmp->string, string))
            return true;
        tmp = tmp->nextElement;
    }
    return false;
}

int numberOfElements(HashTable *table)
{
    int result = 0;
    for (int i = 0; i < table->size; i++)
    {
        TableElement *tmp = table->spreadsheet[i];
        while (tmp != nullptr)
        {
            result++;
            tmp = tmp->nextElement;
        }
    }
    return result;
}

double loadFactor(HashTable *table)
{
    return (double) numberOfElements(table) / table->size;
}

int numberOfWords(HashTable *table)
{
    int result = 0;
    for (int i = 0; i < table->size; i++)
    {
        TableElement *tmp = table->spreadsheet[i];
        while (tmp != nullptr)
        {
            result += tmp->count;
            tmp = tmp->nextElement;
        }
    }
    return result;
}

int numberOfEmptyCells(HashTable *table)
{
    int result = 0;
    for (int i = 0; i < table->size; i++)
        if (table->spreadsheet[i] == nullptr)
            result++;

    return result;
}

void printSpreadsheet(HashTable *hashTable, int cell, std::ostream &stream)
{
    TableElement *tmp = hashTable->spreadsheet[cell];
    while (tmp != nullptr)
    {
        printString(tmp->string, stream);
        stream << " " << tmp->count << std::endl;
        tmp = tmp->nextElement;
    }
}

void printElements(HashTable *table, std::ostream &stream)
{
    for (int i = 0; i < table->size; i++)
        printSpreadsheet(table, i, stream);
}

int printMaxSpreadsheet(HashTable *table, std::ostream &stream)
{
    int maxValue = 0;
    int maxSpreadsheetCell = 0;
    for (int i = 0; i < table->size; i++)
    {
        int current = 0;
        TableElement *tmp = table->spreadsheet[i];
        while(tmp != nullptr)
        {
            current++;
            tmp = tmp->nextElement;
        }
        if (current > maxValue)
        {
            maxValue = current;
            maxSpreadsheetCell = i;
        }
    }
    printSpreadsheet(table, maxSpreadsheetCell, stream);
}
