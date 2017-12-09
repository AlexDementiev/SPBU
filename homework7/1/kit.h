#pragma once
#include "bst.h"

struct Kit;

Kit *createKit();
void deleteKit(Kit *kit);

void add(Kit *kit, int value);
void pop(Kit *kit, int value);
bool isContained(Kit *kit, int value);

void print(Kit *kit);
void printReverse(Kit *kit);
void printKit(Kit *kit);
