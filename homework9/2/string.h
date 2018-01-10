#pragma once

#include <fstream>


struct String;

String *createString(char *line);
void deleteString(String *string);

void concatenation(String *&string, String *secondString);
String *clone(String *string);

bool isEqual(String *string, String *secondString);
int stringLength(String *string);
bool isEmpty(String *string);
char *toChar(String *string);
String *subString(String *string, int begin, int end);
char getChar(String *string, int index);

void printString(String *string, std::ostream &stream);
String *inputString(std::ifstream &stream);
