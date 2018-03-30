#include <iostream>
#include "phonebase.h"

using namespace std;

char *input()
{
    char *line = new char[maxLength];
    cin.getline(line, maxLength);
    return line;
}

int main()
{
    Base *base = load();
    cout << "Phone base: " << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Add" << endl;
    cout << "2 - Find phone" << endl;
    cout << "3 - Find name" << endl;
    cout << "4 - Save" << endl;
    char choice = '\0';

    cin.get(choice);
    cin.ignore();
    while (choice != '0')
    {
        char *name = nullptr;
        char *phone = nullptr;
        switch (choice)
        {
            case '1':
                cout << "Enter name: " << endl;
                name = input();
                cout << "Enter phone: " << endl;
                phone = input();
                add(base, name, phone);
                cout << "OK" << endl;
                break;

            case '2':
                cout << "Enter name: " << endl;
                name = input();
                cout << findPhone(base, name) << endl;
                delete[] name;
                break;

            case '3':
                cout << "Enter phone: " << endl;
                phone = input();
                cout << findName(base, phone) << endl;
                delete[] phone;
                break;

            case '4':
                save(base);
                cout << "OK" << endl;
                break;

            default:
                cout << "Unknown command" << endl;
        }
        cin.get(choice);
        cin.ignore();
    }
    clear(base);
    return 0;
}
