#include <iostream>
#include "kit.h"
using namespace std;

void printInstructions()
{
    cout << "KIT" << endl;
    cout << "0 - exit" << endl;
    cout << "1 - add" << endl;
    cout << "2 - pop" << endl;
    cout << "3 - check" << endl;
    cout << "4 - print" << endl;
}

int main()
{
    Kit *kit = createKit();

    printInstructions();
    int choise = -1;
    cin >> choise;

    while (choise != 0)
    {
        int value = 0;
        switch (choise)
        {
            case 1:
                cout << "Enter number to add: ";
                cin >> value;
                add(kit, value);
                break;

            case 2:
                cout << "Enter number to pop: ";
                cin >> value;
                pop(kit, value);
                break;

            case 3:
                cout << "Enter number to check: ";
                cin >> value;
                cout << value << (isContained(kit, value) ? "" : " not") << " in kit" << endl;
                break;

            case 4:
                cout << " 1 - Increasing Order \n 2 - Decreasing order \n 3 - Tree form" << endl;
                cin >> value;
                if (value == 1)
                    print(kit);
                else if (value == 2)
                    printReverse(kit);
                else if (value == 3)
                    printKit(kit);
                else
                    cout << "Unknown command" << endl;
                break;

            default:
                cout << "Unknown command" << endl;

        }
        cin >> choise;
    }

    deleteKit(kit);

    return 0;
}
