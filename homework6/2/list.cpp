#include "list.h"

struct ListElement
{
    int value;
    ListElement *next;
};

struct List
{
    ListElement *head;
};

List *createList()
{
    List *list = new List;
    list->head = nullptr;
    return list;
}

void deleteList(List *list)
{
    while (!isEmpty(list))
        deleteNext(list);
    delete list;
}

void addAfterHead(List *list, int value)
{
    ListElement *newElement = new ListElement;
    newElement->value = value;

    if (isEmpty(list))
        list->head = newElement;
    else
        newElement->next = list->head->next;

    list->head->next = newElement;
}

void switchToNext(List *list)
{
    if (!isEmpty(list))
        list->head = list->head->next;
}

int deleteNext(List *list)
{
    int result = -1;
    if (!isEmpty(list))
    {
        ListElement *tmp = list->head->next;
        result = tmp->value;

        if (hasOneElement(list))
            list->head = nullptr;
        else
            list->head->next = tmp->next;

        delete tmp;
    }
    return result;
}

bool hasOneElement(List *list)
{
    return !isEmpty(list) && list->head == list->head->next;
}

bool isEmpty(List *list)
{
    return list->head == nullptr;
}
