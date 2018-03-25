#include <iostream>
#include "expressiontree.h"

struct Node
{
    char operation;
    int value;
    bool isLeaf;
    Node *left;
    Node *rigth;
};

struct ExpressionTree
{
    Node *root;
};


ExpressionTree *createTree()
{
    ExpressionTree *tree = new ExpressionTree;
    tree->root = nullptr;
    return tree;
}

void deleteNode(Node *node)
{
    if (node == nullptr)
        return;

    deleteNode(node->left);
    deleteNode(node->rigth);
    delete node;
}

void clearTree(ExpressionTree *tree)
{
    deleteNode(tree->root);
    delete tree;
}

int calculateNode(Node *node)
{
    if (node->isLeaf)
        return node->value;

    switch (node->operation)
    {
        case '+':
            return calculateNode(node->left) + calculateNode(node->rigth);
            break;
        case '-':
            return calculateNode(node->left) - calculateNode(node->rigth);
            break;
    case '*':
        return calculateNode(node->left) * calculateNode(node->rigth);
        break;
    case '/':
        return calculateNode(node->left) / calculateNode(node->rigth);
        break;
    default:
        cout << "Wrong expression\n";
        return 0;
    }
}

int calculate(ExpressionTree *tree)
{
    return calculateNode(tree->root);
}

bool isDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

int toInt(char symbol)
{
    return symbol - '0';
}

Node *inputNode(ifstream &file)
{
    char currentSymbol = file.get();

    Node *newNode = new Node;

    if (currentSymbol  == '(')
    {
        currentSymbol = file.get();
        if (currentSymbol == ' ')
            currentSymbol = '*';
        else
            file.get();

        newNode->isLeaf = false;
        newNode->operation = currentSymbol;
        newNode->left = inputNode(file);
        file.get();
        newNode->rigth = inputNode(file);
        file.get();
    }
    else
    {
        int currentValue = toInt(currentSymbol);
        currentSymbol = file.get();
        while (isDigit(currentSymbol))
        {
            currentValue = currentValue * 10 + toInt(currentSymbol);
            currentSymbol = file.get();
        }
        file.unget();
        newNode->isLeaf = true;
        newNode->left = nullptr;
        newNode->rigth = nullptr;
        newNode->value = currentValue;
    }

    return newNode;
}

void inputTree(ExpressionTree *tree, ifstream &file)
{
    tree->root = inputNode(file);
}

void printInfixNode(Node *node)
{
    if (node->isLeaf)
    {
        cout << node->value;
        return;
    }

    cout << "(";
    printInfixNode(node->left);
    cout << " " << node->operation << " ";
    printInfixNode(node->rigth);
    cout << ")";
}

void printInfixForm(ExpressionTree *tree)
{
    printInfixNode(tree->root);
    cout << endl;
}
