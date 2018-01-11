#pragma once
#include <iostream>

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

int listSize(List *list);
int firstElement(List *list);

void sortList(List *list);
double averageValue(List *list);

void outputList(List *list, std::ostream &output);
void reverseList(List*list);
