#pragma once
#include "avl.h"

struct Set;

Set *createSet();
void deleteSet(Set *set);

void add(Set *set, int value);
void pop(Set *set, int value);
bool isContained(Set *set, int value);

void print(Set *set);
void printReverse(Set *set);
void printSet(Set *set);
