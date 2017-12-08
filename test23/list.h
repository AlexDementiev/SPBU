#pragma once

struct ListElement
{
    ListElement *next;
    int value;
};

struct List
{
    ListElement *head;
    ListElement *tail;
};

List *createList();
void deleteList(List *list);

bool isEmpty(List *list);

void add(List *list, int value);
int get(List *list, int index);

void swapElements(List *list, int index, int position);
void change(List *list, int index, int value);
