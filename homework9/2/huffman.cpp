#include "huffman.h"
#include "priorityQueue.h"


int const maxSymbolCode = 256;


struct HuffmanTree
{
    HuffmanTree *left;
    HuffmanTree *right;

    bool isLeaf;
    char symbol; // if leaf
    int frequency;
};


HuffmanTree *createLeaf(char symbol, int frequency)
{
    HuffmanTree *newLeaf = new HuffmanTree;
    newLeaf->left = nullptr;
    newLeaf->right = nullptr;
    newLeaf->symbol = symbol;
    newLeaf->frequency = frequency;
    newLeaf->isLeaf = true;
}


void deleteHuffmanTree(HuffmanTree *tree)
{
    if (tree == nullptr)
        return;

    deleteHuffmanTree(tree->left);
    deleteHuffmanTree(tree->right);
    delete tree;
}

HuffmanTree *mergeHuffmanTree(HuffmanTree *firstTree, HuffmanTree *secondTree)
{
    HuffmanTree *newTree = new HuffmanTree;
    newTree->left = firstTree;
    newTree->right = secondTree;
    newTree->frequency = firstTree->frequency + secondTree->frequency;
    newTree->isLeaf = false;

    return newTree;
}

void deleteHuffmanCode(HuffmanCode *huffmanCode)
{
    deleteHuffmanTree(huffmanCode->tree);

    for (int i = 0; i < maxSymbolCode; i++)
        if (huffmanCode->codes[i] != nullptr)
            deleteString(huffmanCode->codes[i]);

    delete huffmanCode;
}

void getCodes(HuffmanTree *tree, String **codes, String *currentCode)
{
    if (tree->isLeaf)
    {
        if (stringLength(currentCode) == 0)
        {
            char leftSuffixCode[2] = {'0', '\0'};
            String *leftSuffix = createString(leftSuffixCode);
            concatenation(currentCode, leftSuffix);
            deleteString(leftSuffix);
        }
        codes[(int) tree->symbol] = currentCode;
        return;
    }

    String *leftCode = currentCode;
    String *rightCode = clone(currentCode);

    char leftSuffixCode[2] = {'0', '\0'};
    char rightSuffixCode[2] = {'1', '\0'};
    String *left = createString(leftSuffixCode);
    String *right = createString(rightSuffixCode);
    concatenation(leftCode, left);
    concatenation(rightCode, right);

    getCodes(tree->left, codes, leftCode);
    getCodes(tree->right, codes, rightCode);
}

String **codes(HuffmanTree *tree)
{
    String **codes = new String*[maxSymbolCode];
    for (int i = 0; i < maxSymbolCode; i++)
            codes[i] = nullptr;

    char emptyString[1] = {'\0'};
    getCodes(tree, codes, createString(emptyString));
    return codes;
}

HuffmanCode *encode(String *string)
{
    int frequencies[maxSymbolCode];
    for (int i = 0; i < maxSymbolCode; i++)
        frequencies[i] = 0;

    for (int index = 0; index < stringLength(string); index++)
        frequencies[(int) getChar(string, index)]++;

    PriorityQueue *priorityQueue = createPriorityQueue();
    for (int current = 0; current < maxSymbolCode; current++)
        if (frequencies[current] > 0)
        {
            HuffmanTree *newLeaf = createLeaf((char) current, frequencies[current]);
            add(priorityQueue, newLeaf, frequencies[current]);
        }

    while (!isSimple(priorityQueue))
    {
        HuffmanTree *firstTree = getMin(priorityQueue);
        HuffmanTree *secondTree = getMin(priorityQueue);
        HuffmanTree *newTree = mergeHuffmanTree(firstTree, secondTree);
        int frequenciesNewTree = firstTree->frequency + secondTree->frequency;
        add(priorityQueue, newTree, frequenciesNewTree);
    }

    HuffmanTree *huffmanTree = getMin(priorityQueue);
    deletePriorityQueue(priorityQueue);

    String **code = codes(huffmanTree);

    HuffmanCode *huffmanCode = new HuffmanCode;
    huffmanCode->tree = huffmanTree;
    huffmanCode->codes = code;

    return huffmanCode;
}

String *getCode(HuffmanCode *huffmanCode, char symbol)
{
    return huffmanCode->codes[symbol];
}

int frequency(HuffmanTree *tree)
{
    return tree->frequency;
}

void printTree(HuffmanTree *tree, std::ostream &stream)
{
    if (tree->isLeaf)
    {
        stream << '{' << tree->symbol << ", " << tree->frequency << '}';
        return;
    }

    stream << '(';
    printTree(tree->left, stream);
    printTree(tree->right, stream);
    stream << ')';
}

void printHuffmanTree(HuffmanCode *huffmanCode, std::ostream &stream)
{
    printTree(huffmanCode->tree, stream);
}

void printHuffmanCodes(HuffmanCode *huffmanCode, std::ofstream &stream)
{
    stream << "\n";
    for (int i = 0; i < maxSymbolCode; i++)
    {
        if (huffmanCode->codes[i] != nullptr)
        {
            stream << (char) i << ": ";
            printString(huffmanCode->codes[i], stream);
            stream << "\n";
        }
    }
}
