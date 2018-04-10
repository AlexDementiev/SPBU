#pragma once

#include "tile.h"

struct AVLTree;

AVLTree *createTree();
void deleteTree(AVLTree *tree);

bool contains(AVLTree *tree, Tile *value);
void add(AVLTree *tree, Tile *value);
void remove(AVLTree *tree, Tile *value);
Tile *getMin(AVLTree *tree);

bool isEmpty(AVLTree *tree);
bool hasOneElement(AVLTree *tree);

void printLeft(AVLTree *tree);
void printTree(AVLTree *tree);
void printRight(AVLTree *tree);
