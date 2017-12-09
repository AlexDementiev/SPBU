#include <iostream>
#include "kit.h"

struct Kit
{
    BinarySearchTree *tree;
};

Kit *createKit()
{
    Kit *kit = new Kit;
    kit->tree = createTree();
    return kit;
}

void add(Kit *kit, int value)
{
    add(kit->tree, value);
}

void pop(Kit *kit, int value)
{
    remove(kit->tree, value);
}

void print(Kit *kit)
{
    printLeft(kit->tree);
    std::cout << "\n";
}

void printReverse(Kit *kit)
{
    printRight(kit->tree);
    std::cout << "\n";
}

void printKit(Kit *kit)
{
    printTree(kit->tree);
    std::cout << "\n";
}

bool isContained(Kit *kit, int value)
{
    return contains(kit->tree, value);
}

void deleteKit(Kit *kit)
{
    clearTree(kit->tree);
    delete kit;
}
