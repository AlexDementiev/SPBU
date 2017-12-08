#include "list.h"

List *createList()
{
    List *list = new List{nullptr,nullptr};
    return list;
}

bool isEmpty(List *list)
{
    return list->head == nullptr && list->tail == nullptr;
}

void add(List *list, int value)
{
    if (isEmpty(list))
    {
        list->head = new ListElement;
        list->head->value = value;
        list->head->next = nullptr;
        list->tail = list->head;
    }
    else
    {
        ListElement *tmp = new ListElement;
        tmp->value = value;
        tmp->next = nullptr;
        list->tail->next = tmp;
        list->tail = list->tail->next;
    }
}

void change(List *list, int index, int value)
{
    ListElement *tmp = list->head;
    while (index > 0 && tmp->next != nullptr)
    {
        tmp = tmp->next;
        index--;
    }

    tmp->value = value;
}

void swapElements(List *list, int index, int position)
{
    ListElement *tmp = list->head;
    while (index > 0 && tmp->next != nullptr)
    {
        tmp = tmp->next;
        index--;
    }

    ListElement *temp = list->head;
    while (position > 0 && tmp->next != nullptr)
    {
        temp = temp->next;
        position--;
    }

    int t = tmp->value;
    tmp->value = temp->value;
    temp->value = t;
}

int get(List *list, int index)
{
    if (isEmpty(list))
        return -42;

    ListElement *tmp = list->head;
    while (tmp->next != nullptr && index > 0)
    {
        tmp = tmp->next;
        index--;
    }

    return tmp->value;
}

void deleteList(List *list)
{
    while(!isEmpty(list))
    {
        if (list->head == list->tail)
        {
            delete list->head;
            list->head = nullptr;
            list->tail = nullptr;

            return;
        }

        ListElement *tmp = list->head;
        list->head = list->head->next;
        delete tmp;
    }
}
