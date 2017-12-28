#pragma once

struct StackElement{
    int value;
    StackElement *next;
};

struct Stack{
    StackElement *head;
};

Stack *createStack();
void deleteStack(Stack *stack);

bool isEmpty(Stack *stack);

void push(Stack *stack, int value);
int pop(Stack *stack);

