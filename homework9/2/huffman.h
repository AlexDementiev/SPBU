#pragma once

#include "string.h"


struct HuffmanTree;

struct HuffmanCode
{
    HuffmanTree *tree;
    String **codes;
};

HuffmanTree *createLeaf(char symbol, int frequency);
void deleteHuffmanTree(HuffmanTree *tree);
void deleteHuffmanCode(HuffmanCode *huffmanCode);

HuffmanTree *mergeHuffmanTree(HuffmanTree *firstTree, HuffmanTree *secondTree);
void printHuffmanTree(HuffmanCode *huffmanCode, std::ostream &stream);
void printHuffmanCodes(HuffmanCode *huffmanCode, std::ofstream &stream);

HuffmanCode *encode(String *string);
String *getCode(HuffmanCode *huffmanCode, char symbol);


