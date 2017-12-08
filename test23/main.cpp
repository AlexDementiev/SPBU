#include <iostream>
#include <ctime>
#include "list.h"

using namespace std;

void random(List *list, int size)
{
    unsigned randValue = 11;
    srand(randValue);

    int position = 0;
    while (position < size)
    {
        add(list,rand() % 10);
        position++;
    }
}

void sort(List *list, int size)
{
    int counter = 1;
    while (counter < size)
    {
        int value = get(list,counter);
        int position = counter - 1;
        while (position >= 0 && get(list,position) > value)
        {
            swapElements(list,position + 1,position);
            position--;
        }
        change(list, position + 1,value);
        counter++;
    }
}

void output(List *list, int size)
{
    int index = 0;
    while (index < size)
    {
        cout << get(list,index) << " ";
        index++;
    }
    cout << endl;
}

int main()
{
    List *list = createList();
    random(list, 10);
    output(list, 10);

    sort(list, 10);
    output(list, 10);

    deleteList(list);
    return 0;
}
