#pragma once

struct List;

List *createList();
void deleteList(List *list);

void addAfterHead(List *list, int value);

// Switches head to next element
void switchToNext(List *list);

// Deletes head's next element
int deleteNext(List *list);

bool hasOneElement(List *list);
bool isEmpty(List *list);
