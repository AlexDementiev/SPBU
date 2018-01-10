#pragma once
#include "bst.h"

struct Set;

Set *createSet();
void deleteSet(Set *set);

void add(Set *set, int value);
void pop(Set *set, int value);
bool isContained(Set *kit, int value);

void print(Set *set);
void printReverse(Set *set);
void printSet(Set *set);
