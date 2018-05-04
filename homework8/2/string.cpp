#include "string.h"

struct String
{
    char *string;
    int length;
};

int lineLength(char *line)
{
    int counter = 0;
    while (line[counter] != '\0')
        counter++;
    return counter;
}

String *createString(char *line)
{
    String *string = new String;
    string->length = lineLength(line);
    string->string = new char[string->length];
    for (int counter = 0; counter < string->length; counter++)
        string->string[counter] = line[counter];
    return string;
}

String *clone(String *string)
{
    char *cloneLine = new char[string->length + 1];
    for (int i = 0; i < string->length; i++)
    {
        cloneLine[i] = string->string[i];
    }
    cloneLine[string->length] = '\0';
    String *cloned = createString(cloneLine);
    delete[] cloneLine;
    return cloned;
}

bool isEmpty(String *string)
{
    return (string->length == 0);
}

void concatenation(String *&string, String *secondString)
{
    String *newString = new String;
    newString->length = string->length + secondString->length;
    newString->string = new char[newString->length];

    for (int i = 0; i < string->length; i++)
        newString->string[i] = string->string[i];

    for (int j = 0; j < secondString->length; j++)
        newString->string[string->length + j] = secondString->string[j];

    deleteString(string);
    string = newString;
}

bool isEqual(String *string, String *secondString)
{
    if (string->length != secondString->length)
        return false;
    for (int i = 0; i < string->length; i++)
    {
        if (string->string[i] != secondString->string[i])
            return false;
    }
    return true;
}


void deleteString(String *string)
{
    delete[] string->string;
    delete string;
}

String *subString(String *string, int begin, int end)
{
    char *stringChar = toChar(string);
    char *subStringChar = new char[end - begin + 2];
    for (int i = 0; i <= end - begin; i++)
    {
        subStringChar[i] = stringChar[i + begin];
    }
    subStringChar[end - begin + 1] = '\0';

    String *newString = createString(subStringChar);

    delete[] stringChar;
    delete[] subStringChar;

    return newString;
}

char *toChar(String *string)
{
    int size = string->length + 1;
    char *newChar = new char[size];

    for (int stringIndex = 0; stringIndex < size - 1; stringIndex++)
    {
        newChar[stringIndex] = string->string[stringIndex];
    }
    newChar[size - 1] = '\0';

    return newChar;
}

int stringLength(String *string)
{
    return string->length;
}

void printString(String *string, std::ostream &stream)
{
    for (int i = 0; i < string->length; i++)
        stream << string->string[i];
}

String *inputString(std::istream &stream)
{

    int const bufferSize = 256;

    char *buffer = new char[bufferSize];
    for (int i = 0; i < bufferSize; i++)
        buffer[i] = '\0';

    char emptyLine[1];
    emptyLine[0] = '\0';
    String *result = createString(emptyLine);

    char currentSymbol;
    currentSymbol = stream.get();

    int currentIndex = 0;
    while (currentSymbol != '\0' && currentSymbol != '\n' && !stream.eof())
    {
        if (currentIndex == bufferSize - 1)
        {
            buffer[currentIndex] = '\0';
            String *addition = createString(buffer);
            concatenation(result, addition);
            deleteString(addition);
            for (int j = 0; j < bufferSize; j++)
                buffer[j] = '\0';
            currentIndex = 0;
        }
        buffer[currentIndex] = currentSymbol;
        currentSymbol = stream.get();
        currentIndex++;
    }
    buffer[currentIndex] = '\0';
    String *addition = createString(buffer);
    concatenation(result, addition);
    deleteString(addition);

    delete[] buffer;

    return result;
}

char getChar(String *string, int index)
{
    if (0 <= index && index < string->length)
        return string->string[index];

    return '\0';
}
