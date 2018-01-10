#pragma once

#include "huffman.h"

struct PriorityQueue;

PriorityQueue *createPriorityQueue();
void deletePriorityQueue(PriorityQueue *queue);

bool isSimple(PriorityQueue *queue);

void add(PriorityQueue *queue, HuffmanTree *tree, int priority);
HuffmanTree *getMin(PriorityQueue *queue);
