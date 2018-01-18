#include <iostream>
#include "set.h"
using namespace std;

void printInstructions()
{
    cout << "SET" << endl;
    cout << "0 - exit" << endl;
    cout << "1 - add" << endl;
    cout << "2 - pop" << endl;
    cout << "3 - check" << endl;
    cout << "4 - print increasing order" << endl;
    cout << "5 - print decreasing order" << endl;
    cout << "6 - print tree" << endl;
}

int main()
{
    Set *set = createSet();

    printInstructions();

    enum {exit, addToSet, popFromSet, check, printIncreasingOrder, printDecreasingOrder, printTree};


    int choice = 0;
    cin >> choice;
    while (choice != 0)
    {
        int value = 0;
        switch (choice)
        {
            case addToSet:
                cout << "Enter number to add: ";
                cin >> value;
                add(set, value);
                break;

            case popFromSet:
                cout << "Enter number to pop: ";
                cin >> value;
                pop(set, value);
                break;

            case check:
                cout << "Enter number to check: ";
                cin >> value;
                cout << value << (isContained(set, value) ? "" : " not") << " in set" << endl;
                break;

            case printIncreasingOrder:
                print(set);
                break;
            case printDecreasingOrder:
                printReverse(set);
                break;
            case printTree:
                printSet(set);
                break;
            case exit:
                return 0;

            default:
                cout << "Unknown command" << endl;

        }
        cin >> choice;
    }

    deleteSet(set);

    return 0;
}
