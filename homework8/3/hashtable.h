#pragma once

#include <fstream>
#include "string.h"

struct HashTable;

HashTable *createTable();
void deleteTable(HashTable *table);

void add(HashTable *table, String *string);
bool contains(HashTable *table, String *string);

double loadFactor(HashTable *table);
int numberOfElements(HashTable *table);
int numberOfWords(HashTable *table);
int numberOfEmptyCells(HashTable *table);

int printMaxSpreadsheet(HashTable *table, std::ostream &stream);
void printElements(HashTable *table, std::ostream &stream);
