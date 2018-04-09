#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    int warriorsNumber = 0;
    int skipNumber = 0;
    cout << "Enter the number of warriors and the number to be skipped: ";
    cin >> warriorsNumber >> skipNumber;

    List *warriors = createList();
    for (int i = warriorsNumber; i > 0; i--)
        addAfterHead(warriors, i);

    while (!hasOneElement(warriors))
    {
        for (int j = 0; j < skipNumber - 1; j++)
            switchToNext(warriors);
        deleteNext(warriors);
    }

    cout << "The warrior number " << deleteNext(warriors) << " won't be killed" << endl;
    deleteList(warriors);
    return 0;
}
