#include <iostream>
#include <cstring>
#include "huffman.h"
#include "queue.h"

using namespace std;

const int maxSize = 10000;

bool isLeaf(Node *node)
{
    return node->symbol != -1;
}

Node *createNode(int frequency, char symbol, Node *left, Node *right)
{
    Node *newNode = new Node;
    newNode->left = left;
    newNode->right = right;
    newNode->frequency = frequency;
    newNode->symbol = symbol;
    return newNode;
}

void deleteNode(Node *node)
{
    if (!node)
        return;

    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}

Node *getNode(char *tree, int &i)
{
    while ((i < strlen(tree)) && ((tree[i] == ' ') || (tree[i] == ')')))
    {
        i++;
    }
    if ((tree[i] == '(') && (tree[i + 2] == '1'))
    {
        Node *node = createNode(0, -1, nullptr, nullptr);
        i += 4;
        node->left = getNode(tree, i);
        node->right = getNode(tree, i);
        return node;
    }
    else if (tree[i] == '(')
    {
        Node *node = createNode(0, tree[i + 1], nullptr, nullptr);
        i += 3;
        node->left = getNode(tree, i);
        node->right = getNode(tree, i);
        return node;
    }
    else
    {
        if (tree[i + 4] == ')')
            i += 6;
        else
            i += 5;

        return nullptr;
    }
}

void getChar(Node *node, int &i, char *code, ofstream &fout)
{
    if (isLeaf(node))
    {
        fout << node->symbol;
        return;
    }

    i++;
    if (code[i] == '1')
        getChar(node->right, i, code, fout);
    else
        getChar(node->left, i, code, fout);
}

void huffmanDecode(std::ifstream &fin, ofstream &fout)
{
    char *tree = new char[maxSize]{};
    char *temp = new char[maxSize]{};

    fin.getline(temp, maxSize, '\n');
    strcat(tree, temp);
    if (fin.get() == ' ')
    {
        strcat(tree, "\n ");
        fin.getline(temp, maxSize, '\n');
        strcat(tree, temp);
    }
    delete [] temp;
    int i = 0;
    Node *root = getNode(tree, i);
    char *code = new char[maxSize]{};
    fin >> code;
    i = -1;
    int size = strlen(code);
    while (i < size - 1)
    {
        getChar(root, i, code, fout);
    }

    delete [] code;
    delete [] tree;
    deleteNode(root);
}
