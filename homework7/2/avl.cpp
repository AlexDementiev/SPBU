#include <iostream>
#include "avl.h"

struct AVLNode
{
    int value;
    int height;
    AVLNode *left;
    AVLNode *rigth;
};

AVLTree *createTree()
{
    AVLTree *tree = new AVLTree;
    tree->root = nullptr;
    return tree;
}

void printLeftNode(AVLNode *node)
{
    if (node == nullptr)
        return;

    printLeftNode(node->left);
    std::cout << node->value << " ";
    printLeftNode(node->rigth);
}

void printLeft(AVLTree *tree)
{
    printLeftNode(tree->root);
    std::cout << "\n";
}

void printTreeNode(AVLNode *node)
{
    if (node == nullptr)
    {
        std::cout << " null";
        return;
    }

    std::cout << "(" << node->value << " ";
    printTreeNode(node->left);
    printTreeNode(node->rigth);
    std::cout << ")";
}

void printTree(AVLTree *tree)
{
    printTreeNode(tree->root);
    std::cout << "\n";
}

void printRightNode(AVLNode *node)
{
    if (node == nullptr)
        return;

    printRightNode(node->rigth);
    std::cout << node->value;
    printRightNode(node->left);
}

void printRight(AVLTree *tree)
{
    printRightNode(tree->root);
    std::cout << "\n'";
}

int height(AVLNode *node)
{
    return node ? node->height : 0;
}

int balanceFaktor(AVLNode *node)
{
    return height(node->rigth) - height(node->left);
}

void updateHeight(AVLNode *node)
{
    int heightLeft = height(node->left);
    int heightRight = height(node->rigth);
    node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

void rotateRight(AVLNode *&root)
{
    AVLNode *pivot = root->left;
    root->left = pivot->rigth;
    pivot->rigth = root;
    updateHeight(root);
    updateHeight(pivot);
    root = pivot;
}

void rotateLeft(AVLNode *&root)
{
    AVLNode *pivot = root->rigth;
    root->rigth = pivot->left;
    pivot->left = root;
    updateHeight(root);
    updateHeight(pivot);
    root = pivot;
}

void balance(AVLNode *&node)
{
    updateHeight(node);

    if (balanceFaktor(node) == 2)
    {
        if (balanceFaktor(node->rigth) < 0)
            rotateRight(node->rigth);
        rotateLeft(node);
    }
    if (balanceFaktor(node) == -2)
    {
        if (balanceFaktor(node->left) > 0)
            rotateLeft(node->left);
        rotateRight(node);
    }
}

void clearNode(AVLNode *node)
{
    if (node == nullptr)
        return;

    clearNode(node->left);
    clearNode(node->rigth);
    delete node;
}

void clearTree(AVLTree *tree)
{
    clearNode(tree->root);
    tree->root = nullptr;
}

bool containsNode(AVLNode *node, int value)
{
    if (node == nullptr)
        return false;

    if (node->value == value)
        return true;

    if (node->value > value)
        return containsNode(node->left, value);
    else
        return containsNode(node->rigth, value);
}

bool contains(AVLTree *tree, int value)
{
    return containsNode(tree->root, value);
}

AVLNode *createNode(int value)
{
    AVLNode *node = new AVLNode;
    node->value = value;
    node->left = nullptr;
    node->rigth = nullptr;
    updateHeight(node);
    return node;
}

void addNode(AVLNode *&node, int value)
{
    if (node == nullptr)
        node = createNode(value);

    if (node->value == value)
        return;

    if (value < node->value)
        addNode(node->left, value);
    else
        addNode(node->rigth, value);

    balance(node);
}

void add(AVLTree *tree, int value)
{
    addNode(tree->root, value);
}

AVLNode *findMax(AVLNode *node)
{
    while (node->rigth != nullptr)
        node = node->rigth;
    return node;
}

void removeNode(AVLNode *&node, int value)
{
    if (node == nullptr)
        return;

    if (node->value == value)
    {
        if (node->left == nullptr && node->rigth == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr)
        {
            AVLNode *temp = node->rigth;
            delete node;
            node = temp;
            balance(node);
        }
        else if (node->rigth == nullptr)
        {
            AVLNode *temp = node->left;
            delete node;
            node = temp;
            balance(node);
        }
        else
        {
            AVLNode *maxNode = findMax(node->left);
            int maxValue = maxNode->value;
            removeNode(node, maxValue);
            node->value = maxValue;
            balance(node);
        }
        return;
    }

    if (value < node->value)
        removeNode(node->left, value);
    else
        removeNode(node->rigth, value);
}

void remove(AVLTree *tree, int value)
{
    removeNode(tree->root, value);
}
