#include "stack.h"


Stack *createStack()
{
    Stack *stack = new Stack;
    stack->head = nullptr;
    return stack;
}

void deleteStack(Stack *stack)
{
    StackElement *tmp = nullptr;
    while (!isEmpty(stack))
    {
        tmp = stack->head->next;
        delete stack->head;
        stack->head = tmp;
    }
    delete stack;
}

int popInt(Stack *stack)
{
    if (isEmpty(stack))
        return -1;

    int value = stack->head->value;
    StackElement *tmp = stack->head->next;
    delete stack->head;
    stack->head = tmp;
    return value;
}

void pushInt(Stack *stack, int value)
{
    StackElement *newElement = new StackElement;
    newElement->value = value;
    newElement->next = stack->head;
    stack->head = newElement;
}

bool isEmpty(Stack *stack)
{
    return stack->head == nullptr;
}

char popChar(Stack *stack)
{
    return (char) popInt(stack);
}

void pushChar(Stack *stack, char value)
{
    pushInt(stack, (int) value);
}

int length(Stack *stack)
{
    StackElement *tmp = stack->head;
    int length = 0;
    while (tmp != nullptr)
    {
        length++;
        tmp = tmp->next;
    }
    return length;
}

char *toString(Stack *stack)
{
    int outputStringLength = length(stack);
    char *outputString = new char[outputStringLength];

    for (int i = outputStringLength - 1; i >= 0; i--)
        outputString[i] = popChar(stack);

    return outputString;
}
