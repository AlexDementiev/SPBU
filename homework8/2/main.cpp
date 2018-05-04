#include <iostream>
#include "string.h"

using namespace std;

void printEquality(String *string1, String *string2)
{
    cout << "Strings \"";
    printString(string1, cout);
    cout << "\" and \"";
    printString(string2, cout);
    if (isEqual(string1, string2))
        cout << "\" are equal" << endl;
    else
        cout << "\" aren't equal" << endl;
}

int main()
{

    cout << "Enter two strings: " << endl;

    String *string1 = inputString(cin);
    String *string2 = inputString(cin);

    printEquality(string1, string2);

    printString(string1, cout);
    cout << " + ";
    printString(string2, cout);
    concatenation(string1, string2);
    cout << " = ";
    printString(string1, cout);
    cout << endl;

    String *cloned = clone(string1);
    printEquality(cloned, string1);
    printEquality(cloned, string2);

    String *trunc = subString(cloned, 1, stringLength(cloned) - 1);
    cout << "Deleted first symbol: ";
    printString(trunc, cout);
    cout << endl;

    cout << "First and last are: " << getChar(trunc, 0) << " " << getChar(trunc, stringLength(trunc) - 1) << endl;

    deleteString(string1);
    deleteString(string2);
    deleteString(cloned);
    deleteString(trunc);

    return 0;
}
