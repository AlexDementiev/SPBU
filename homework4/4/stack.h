#pragma once

struct StackElement
{
    int value;
    StackElement *next;
};

struct Stack
{
    StackElement *head;
};

Stack *createStack();
void deleteStack(Stack *stack);

int popInt(Stack *stack);
void pushInt(Stack *stack, int value);

bool isEmpty(Stack *stack);

