#include "list.h"

List *createList()
{
    List *list = new List{nullptr, 0};
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

//void deleteElement(List *list, int value)
//{
//    if (isSiple(list))
//    {
//        delete list->head;
//        list->head = nullptr;
//        list->dimension = 0;
//        return;
//    }



//    if (!isEmpty(list))
//    {
//        if (value == 1)
//        {
//            ListElement *tmp = list->head->next;
//            while (tmp->next != list->head)
//                tmp = tmp->next;

//            ListElement *temp = list->head;
//            list->head = list->head->next;
//            list->dimension--;
//            tmp->next = list->head;
//            delete temp;

//            return ;
//        }

//        ListElement *tmp = list->head;
//        while (value > 2)
//        {
//            tmp = tmp->next;
//            value--;
//        }

//        ListElement *temp = tmp->next;
//        tmp->next = temp->next;
//        list->dimension--;
//        delete temp;

//        list->head = tmp->next;
//    }
//}

void clearList(List *list)
{
    if (!isEmpty(list))
    {
        ListElement *tmp = list->head->next;
        while (tmp != list->head)
        {
            ListElement *temp = tmp;
            tmp = tmp->next;
            delete temp;
        }
    }
    delete list->head;
    delete list;
    return;
}

int listSize(List *list)
{
    return list->dimension;
}

int firstElement(List *list)
{
    return list->head->value;
}

ListElement *get(List *list, int index)
{
    ListElement *tmp = list->head;
    index %= listSize(list);
    while (index > 0)
    {
        tmp = tmp->next;
        index--;
    }
    return tmp;
}

void outputList(List *list, std::ostream &output)
{
    int size = listSize(list);
    ListElement *tmp = list->head;
    while (size > 0)
    {
        output << tmp->value << " ";
        size--;
        tmp = tmp->next;
    }
    output << "\n";
}

void sortList(List *list)
{
    int index = 0;
    int size = listSize(list);
    while (index < size - 1)
    {
        int current = 0;
        while (current < size - 1)
        {
            ListElement *tmp = get(list, current);
            ListElement *temp = get(list, current + 1);
            if (tmp->value > temp->value)
            {
                int c = tmp->value;
                tmp->value = temp->value;
                temp->value = c;
            }
            current++;
        }
        index++;
    }
}

double averageValue(List *list)
{
    int size = listSize(list);
    int index = 0;
    int sum = 0;
    ListElement *tmp = list->head;
    while (index < size)
    {
        sum += tmp->value;
        tmp = tmp->next;
        index++;
    }
    return (double)sum / (double)size;
}

void reverseList(List *list)
{
    int size = listSize(list);
    int index = 1;
    while (index <= size / 2)
    {
        ListElement *tmp = get(list, index - 1);
        ListElement *temp = get(list, size - index);
        int c = tmp->value;
        tmp->value = temp->value;
        temp->value = c;
        index++;
    }
}
