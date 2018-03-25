#include <iostream>
#include <string.h>
#include "huffman.h"
#include "queue.h"

using namespace std;

void calculateFrequency(char *string, int amountSymbols, int *frequency)
{
    for (int i = 0; i < amountSymbols; i++)
    {
        frequency[string[i]]++;
    }
}

void printFrequency(int *frequency)
{
    cout << "character frequency: " << '\n';
    for (int i = 0; i < maxSize; i++)
    {
        if (frequency[i])
            cout << (char)i << " - " << frequency[i] << '\n';
    }
}

bool isLeaf(Node *node)
{
    return node->symbol != -1;
}

void getCodes(Node *node, char *string, char **code)
{
    if (isLeaf(node))
    {
        strcat(code[node->symbol], string);
        return;
    }

    if (node->left)
    {
        strcat(string, "0");
        getCodes(node->left, string, code);
        string[strlen(string) - 1] = '\0';
    }

    if (node->right)
    {
        strcat(string, "1");
        getCodes(node->right, string, code);
        string[strlen(string) - 1] = '\0';
    }
}

void printTree(Node *node, ofstream &fout)
{
    if (node == nullptr)
    {
        fout << "null";
        return;
    }
    fout << "(";
    if (node->symbol == -1)
        fout << -1 << ' ';
    else
        fout << node->symbol << ' ';
    printTree(node->left, fout);
    fout << ' ';
    printTree(node->right, fout);
    fout << ')';
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

bool isContainsOneSymbol(char *string)
{
    char symbol = string[0];
    for (int i = 1; i < strlen(string); i++)
    {
        if (symbol != string[i])
        {
            return false;
        }
    }
    return true;
}

void processSingleCharCase(char *string, ofstream &fout)
{
    fout << "(-1 " << string[0] << ' ' << "null)" << '\n';
    for (int i = 0; i < strlen(string); i++)
    {
        fout << 0;
    }
}

void deleteNode(Node *node)
{
    if (node == nullptr)
        return;

    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}

char **createCharMatrix(int size)
{
    char **result = new char*[size];
    for (int i = 0; i < size; i++)
    {
        result[i] = new char[size]{};
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = 0;
        }
    }
    return result;
}

void deletedCharMatrix(char **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void huffmanEncode(char *string, ofstream &fout)
{
    int *frequency = new int[maxSize]{0};
    calculateFrequency(string, strlen(string), frequency);
    printFrequency(frequency);

    if (isContainsOneSymbol(string))
    {
        processSingleCharCase(string, fout);
        return;
    }

    Queue *queue = createQueue();
    for (int i = 0; i < maxSize; i++)
    {
        if (frequency[i])
        {
            queuePush(queue, createNode(frequency[i], (char)(i), nullptr, nullptr));
        }
    }

    while (queueSize(queue) > 1)
    {
        Node *node1 = queueTop(queue);
        queuePop(queue);
        Node *node2 = queueTop(queue);
        queuePop(queue);
        queuePush(queue, createNode(node1->frequency + node2->frequency, -1, node1, node2));
    }

    Node *root = queueTop(queue);
    queuePop(queue);

    queueDelete(queue);
    char **code = createCharMatrix(maxSize);
    char *temp = new char[maxSize]{};
    getCodes(root, temp, code);

    printTree(root, fout);
    fout << '\n';

    for (int i = 0; i < strlen(string); i++)
    {
        fout << code[string[i]];
    }

    deleteNode(root);
    deletedCharMatrix(code, maxSize);
    delete [] frequency;
    delete [] temp;
}
