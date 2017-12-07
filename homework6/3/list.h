#pragma once

struct ListElement
{
    ListElement *next;
    char *name;
    char *number;
};

struct List
{
    ListElement *head;
    ListElement *tail;
    int capasity;
};

List *createList();
void deleteList(List *list);

bool isEmpty(List *list);

void add(List *list, ListElement *newContact);
ListElement *get(List *list, char *string);
