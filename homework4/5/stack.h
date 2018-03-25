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

int pop(Stack *stack);
int peek(Stack *stack);
void push(Stack *stack, int value);

bool isEmpty(Stack *stack);

