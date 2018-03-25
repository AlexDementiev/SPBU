#include <algorithm>
#include "queue.h"

using namespace std;

struct QueueNode
{
    Node *data;
    QueueNode *next;
};

struct Queue
{
    QueueNode *head;
    int size;
};

Queue *createQueue()
{
    Queue *newQueue = new Queue;
    newQueue->head = nullptr;
    newQueue->size = 0;
    return newQueue;
}

QueueNode *createQueueNode(Node *data, QueueNode *next)
{
    QueueNode *newNode = new QueueNode;
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

void queuePush(Queue *queue, Node *node)
{
    if (!queue->head)
    {
        queue->head = createQueueNode(node, nullptr);
        queue->size = 1;
        return;
    }

    QueueNode *temp = createQueueNode(node, queue->head);
    queue->head = temp;
    queue->size++;
}

int findMin(Queue *queue)
{
    int result = 1000000;
    QueueNode *temp = queue->head;
    while (temp)
    {
        result = min(result, temp->data->frequency);
        temp = temp->next;
    }
    return result;
}

Node *queueTop(Queue *queue)
{
    int minFrequency = findMin(queue);

    QueueNode *temp = queue->head;
    while (temp->data->frequency != minFrequency)
    {
        temp = temp->next;
    }

    Node *result = new Node;
    result->left = temp->data->left;
    result->right = temp->data->right;
    result->symbol = temp->data->symbol;
    result->frequency = minFrequency;

    return result;
}

void removeFromHead(Queue *queue)
{
    QueueNode *tempNode = queue->head;
    queue->head = tempNode->next;
    delete tempNode->data;
    delete tempNode;
    queue->size--;
}

void queuePop(Queue *queue)
{
    int minFrequency = findMin(queue);

    if (queue->head->data->frequency == minFrequency)
    {
        removeFromHead(queue);
        return;
    }

    QueueNode *temp = queue->head;
    while (temp->next->data->frequency != minFrequency)
    {
        temp = temp->next;
    }

    QueueNode *tempNode = temp->next;
    temp->next = tempNode->next;
    delete tempNode->data;
    delete tempNode;
    queue->size--;
}

void queueDelete(Queue *queue)
{
    if (!queue)
    {
        return;
    }

    if (!queue->head)
    {
        delete queue;
        return;
    }

    QueueNode *tempNode = queue->head;
    while (tempNode->next)
    {
        QueueNode *toDelete = tempNode;
        tempNode = tempNode->next;
        delete toDelete->data;
        delete toDelete;
    }
    delete tempNode->data;
    delete tempNode;
    delete queue;
}

int queueSize(Queue *queue)
{
    return queue->size;
}
