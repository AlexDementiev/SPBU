#include "list.h"

List *createList()
{
    List *list = new List{nullptr,0};
    return list;
}

bool isEmpty(List *list)
{
    return list->head == nullptr;
}

bool isSiple(List *list)
{
    if (!isEmpty(list))
        return list->head == list->head->next;
    return false;
}

void add(List *list, int value)
{
    if (isEmpty(list))
    {
        list->head = new ListElement;
        list->head->next = list->head;
        list->head->value = value;
        list->dimension++;
        return;
    }

    ListElement *tmp = list->head;
    while (tmp->next != list->head)
        tmp = tmp->next;
    tmp->next = new ListElement;
    tmp->next->next = list->head;
    tmp->next->value = value;
    list->dimension++;
    return;
}

void deleteElement(List *list, int value)
{
    if (isSiple(list))
    {
        if (list->head->value == value)
            delete list->head;
        list->head = nullptr;
        list->dimension = 0;

        return;
    }

    if (!isEmpty(list))
    {
        if (value == 1)
        {
            ListElement *tmp = list->head->next;
            while (tmp->next != list->head)
                tmp = tmp->next;

            ListElement *temp = list->head;
            list->head = list->head->next;
            list->dimension--;
            tmp->next = list->head;
            delete temp;

            return ;
        }

        ListElement *tmp = list->head;
        while (value > 2)
        {
            tmp = tmp->next;
            value--;
        }

        ListElement *temp = tmp->next;
        tmp->next = temp->next;
        list->dimension--;
        delete temp;

        list->head = tmp->next;
    }
}

void clearList(List *list)
{
    while (!isEmpty(list))
        deleteElement(list,1);
    return;
}
