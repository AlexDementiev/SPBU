#pragma once

struct Node
{
    char symbol;
    int frequency;
    Node *left;
    Node *right;
};

struct Queue;

Queue *createQueue();
void queuePush(Queue *queue, Node *node);
void queuePop(Queue *queue);
void queueDelete(Queue *queue);
int queueSize(Queue *queue);
Node *queueTop(Queue *queue);

