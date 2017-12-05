#pragma once

struct ListElement
{
    ListElement *next;
    int value;
};

struct List
{
    ListElement *head;
    int dimension;
};

List *createList();
void clearList(List *list);

bool isEmpty(List *list);
bool isSiple(List *list);

void add(List *list, int value);
void deleteElement(List *list, int value);
