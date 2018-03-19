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

char popChar(Stack *stack);
void pushChar(Stack *stack, char value);

bool isEmpty(Stack *stack);
int length(Stack *stack);

char *toString(Stack *stack);
