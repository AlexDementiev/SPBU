#include "priorityQueue.h"

struct PriorityQueueElement
{
    PriorityQueueElement *next;
    HuffmanTree *tree;
    int priority;
};

struct PriorityQueue
{
    PriorityQueueElement *head;
    PriorityQueueElement *tail;
};

PriorityQueue *createPriorityQueue()
{
    PriorityQueue *queue = new PriorityQueue;
    queue->head = nullptr;
    queue->tail = nullptr;
}

bool isEmpty(PriorityQueue *queue)
{
    return queue->head == nullptr && queue->tail == nullptr;
}

bool isSimple(PriorityQueue *queue)
{
    return !isEmpty(queue) && queue->head == queue->tail;
}

void add(PriorityQueue *queue, HuffmanTree *tree, int priority)
{
    if (isEmpty(queue))
    {
        queue->head = new PriorityQueueElement;
        queue->head->next = nullptr;
        queue->head->tree = tree;
        queue->head->priority = priority;
        queue->tail = queue->head;

        return;
    }

    if (isSimple(queue))
    {
        if (priority > queue->head->priority)
        {
            queue->tail = new PriorityQueueElement;
            queue->tail->next = nullptr;
            queue->tail->priority = priority;
            queue->tail->tree = tree;
            queue->head->next = queue->tail;
        }
        else
        {
            queue->head = new PriorityQueueElement;
            queue->head->next = queue->tail;
            queue->head->tree = tree;
            queue->head->priority = priority;
            queue->head->next = queue->tail;
        }
        return;
    }

    if (priority <= queue->head->priority)
    {
        PriorityQueueElement *tmp = new PriorityQueueElement;
        tmp->next = queue->head;
        tmp->tree = tree;
        tmp->priority = priority;
        queue->head = tmp;

        return;
    }

    PriorityQueueElement *tmp = queue->head->next;
    PriorityQueueElement *temp = queue->head;
    while (tmp != nullptr && priority > tmp->priority)
    {
        temp = tmp;
        tmp = tmp->next;
    }

    temp->next = new PriorityQueueElement;
    temp->next->priority = priority;
    temp->next->tree = tree;
    temp->next->next = tmp;

    if (temp == queue->tail)
        queue->tail = temp->next;
}

HuffmanTree *getMin(PriorityQueue *queue)
{
    if (isSimple(queue))
    {
        HuffmanTree *tree = queue->head->tree;
        queue->head = nullptr;
        queue->tail = nullptr;

        return tree;
    }

    HuffmanTree *tree = queue->head->tree;
    PriorityQueueElement *tmp = queue->head;
    queue->head = queue->head->next;

    delete tmp;
    return tree;
}

void deletePriorityQueue(PriorityQueue *queue)
{
    while (!isEmpty(queue))
        getMin(queue);

    delete queue;
}
