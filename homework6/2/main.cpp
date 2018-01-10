#include <iostream>
#include "list.h"

using namespace std;

void buildList(List *list, int size)
{
    int counter = 1;
    while (counter <= size)
    {
        add(list, counter);
        counter++;
    }
    return;
}

int main()
{
    cout << "Enter the number of soldiers and the number of the retring soldier: ";
    int n = 0;
    int m = 0;
    cin >> n >> m;

    List *warriors = createList();
    buildList(warriors, n);

    int index = 0;
    if (m > n)
         index = m % n;
    else
        index = m;

    while (!isSiple(warriors))
    {
        if (m > listSize(warriors))
            index = m % listSize(warriors);
        if (index == 0)
            index = listSize(warriors);
        deleteElement(warriors, index);
    }
    cout <<"The position of the surviving soldier: " <<  firstElement(warriors);
    clearList(warriors);

    return 0;
}
