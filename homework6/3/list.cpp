#include "list.h"

List *createList()
{
    List *list = new List{nullptr,nullptr,0};
    return list;
}

bool isEmpty(List *list)
{
    return list->head == nullptr && list->tail == nullptr;
}

void add(List *list, ListElement *newContact)
{
    if (isEmpty(list))
    {
        list->head = new ListElement;
        list->head->name = newContact->name;
        list->head->number = newContact->number;
        list->head->next = nullptr;
        list->tail = list->head;
        list->capasity++;
    }
    else
    {
        ListElement *tmp = new ListElement;
        tmp->name = newContact->name;
        tmp->number = newContact->number;
        tmp->next = nullptr;
        list->tail->next = tmp;
        list->tail = list->tail->next;
        list->capasity++;
    }
}

int length(char *string)
{
    int counter = 0;
    while (string[counter] != '\0')
        counter++;

    return counter;
}

bool isEqual(char *string, char *subString)
{
    if (length(string) != length(subString))
        return false;

    int index = 0;
    bool flag = true;
    while (string[index] != '\0' && flag)
    {
        if (string[index] != subString[index])
            flag = false;
        index++;
    }

    return flag;
}

ListElement *get(List *list, char *string)
{
    if (isEmpty(list))
        return nullptr;

    ListElement *tmp = list->head;
    while (tmp != nullptr && !isEqual(tmp->name,string) && !isEqual(tmp->number,string))
        tmp = tmp->next;
    return tmp;
}

void deleteList(List *list)
{
    while(!isEmpty(list))
    {
        if (list->head == list->tail)
        {
            delete[] list->head->name;
            delete[] list->head->number;
            list->head = nullptr;
            list->tail = nullptr;

            return;
        }

        ListElement *tmp = list->head;
        list->head = list->head->next;
        delete[] tmp->name;
        delete[] tmp->number;
        delete tmp;
    }
}
