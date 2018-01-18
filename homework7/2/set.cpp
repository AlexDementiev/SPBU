#include <iostream>
#include "set.h"

struct Set
{
    AVLTree *tree;
};

Set *createSet()
{
    Set *set = new Set;
    set->tree = createTree();
    return set;
}

void add(Set *set, int value)
{
    add(set->tree, value);
}

void pop(Set *set, int value)
{
    remove(set->tree, value);
}

void print(Set *set)
{
    printLeft(set->tree);
    std::cout << "\n";
}

void printReverse(Set *set)
{
    printRight(set->tree);
    std::cout << "\n";
}

void printSet(Set *set)
{
    printTree(set->tree);
    std::cout << "\n";
}

bool isContained(Set *set, int value)
{
    return contains(set->tree, value);
}

void deleteSet(Set *set)
{
    clearTree(set->tree);
    delete set->tree;
    delete set;
}
