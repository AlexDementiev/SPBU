#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

void runMenu()
{
    cout << "****************************************\n";
    cout << "select one of the menu items: \n";
    cout << "0 - sign out.\n";
    cout << "1 - add an entry (name and phone).\n";
    cout << "2 - find the phone by name.\n";
    cout << "3 - find the name by phone.\n";
    cout << "4 - save the current data to a file.\n";
    cout << "****************************************\n";
}

ListElement *inputNewContact()
{
    ListElement *tmp = new ListElement;

    char *name = new char[50]{'\0'};
    cout << "Enter the name: ";
    cin >> name;
    tmp->name = name;

    char *number = new char[50]{'\0'};
    cout << "Enter the number: ";
    cin >> number;
    tmp->number = number;

    return tmp;
}

void getNumber(List *list)
{
    char *name = new char[50]{'\0'};
    cout << "Enter the name: ";
    cin >> name;

    ListElement *tmp = get(list,name);
    if (tmp == nullptr)
        cout << "This contact does not exist." << endl;
    else
        cout << "Found number: " << tmp->number << endl;
}

void getName(List *list)
{
    char *number = new char[50]{'\0'};
    cout << "Enter the number: ";
    cin >> number;

    ListElement *tmp = get(list,number);
    if (tmp == nullptr)
        cout << "This contact does not exist." << endl;
    else
        cout << "The name is: " << tmp->name << endl;
}

int main()
{
    ifstream input("PhoneBook.txt");
    List *phoneBook = createList();

    if (input.is_open())
    {
        while (input)
        {
            ListElement *newContact = new ListElement;

            char *newName = new char[50]{'\0'};
            input >> newName;
            if (newName[0] == '\0')
                continue;
            newContact->name = newName;

            char *newNumber = new char[50]{'\0'};
            input >> newNumber;
            newContact->number = newNumber;

            add(phoneBook,newContact);
        }
    }

    input.close();

    runMenu();

    int userChoise = -1;
    bool flag = true;
    while (flag)
    {
        cin >> userChoise;
        if (userChoise == 0)
            flag = false;

        if (userChoise > 0 && userChoise < 5)
        {
            switch (userChoise)
            {
                case 1 :
                    add(phoneBook,inputNewContact()); break;
                case 2 :
                    getNumber(phoneBook); break;
                case 3 :
                    getName(phoneBook); break;
                case 4 :
                {
                    ofstream output("PhoneBook.txt");

                    ListElement *tmp = phoneBook->head;
                    while (tmp != nullptr)
                    {
                        output << tmp->name << " " << tmp->number << "\n";
                        tmp = tmp->next;
                    }

                    output.close();
                    break;
                }
            }
        }
        else if (userChoise != 0)
        {
            cout << "Invalid data, try again :(\n";
            continue;
        }
    }

    deleteList(phoneBook);

        
    return 0;
}
