#pragma once

#include "tile.h"

struct AVLNode;

struct AVLTree
{
    AVLNode *root;
};

AVLTree *createTree();
void clearTree(AVLTree *tree);

bool contains(AVLTree *tree, Tile *value);
void add(AVLTree *tree, Tile *value);
void removeTile(AVLTree *tree, Tile *value);
Tile *getMin(AVLTree *tree);

bool isEmpty(AVLTree *tree);
bool isSimple(AVLTree *tree); // queue has one element

void printLeft(AVLTree *tree);
void printTree(AVLTree *tree);
void printRigth(AVLTree *tree);
