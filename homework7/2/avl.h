#pragma once

struct AVLNode;

struct AVLTree
{
    AVLNode *root;
};

AVLTree *createTree();
void clearTree(AVLTree *tree);

bool contains(AVLTree *tree, int value);
void add(AVLTree *tree, int value);
void remove(AVLTree *tree, int value);

void printLeft(AVLTree *tree);
void printTree(AVLTree *tree);
void printRight(AVLTree *tree);
