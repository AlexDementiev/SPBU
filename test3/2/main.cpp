#include <iostream>
#include <ctime>
#include <cstdlib>
#include "list.h"

using namespace std;

int main()
{
    cout << "Menu: " << endl;
    cout << "0 - exit" << endl;
    cout << "1 - random array" << endl;
    cout << "2 - reverse array" << endl;
    cout << "3 - print array" << endl;

    enum {exit, random, reverse, print};

    List *list = createList();

    int choice = 0;
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case random:
        {
            int size = 0;
            int left = 0;
            int right = 0;
            cout << "Enter size, left, right: ";
            cin >> size >> left >> right;
            srand(time(0));
            for (int i = 0; i < size; i++)
                add(list, rand() % (right - left) + left);
            outputList(list, cout);
        }
        break;
        case reverse:
            reverseList(list);
            break;
        case print:
            outputList(list, cout);
            break;
        case exit:
        {
            clearList(list);
            return 0;
        }
        }
        cin >> choice;
    }

    clearList(list);
    return 0;
}
