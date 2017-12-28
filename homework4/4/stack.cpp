#include "stack.h"


Stack *createStack() {
    Stack *stack = new Stack{nullptr};
    return stack;
}

bool isEmpty(Stack *stack) {
    return stack->head == nullptr;
}

void push(Stack *stack, int value) {
    if (isEmpty(stack)) {
        stack->head = new StackElement{value,nullptr};
        return;
    }

    StackElement *tmp = stack->head;
    stack->head = new StackElement{value,tmp};
    return;
}
int pop(Stack *stack) {
    int result = -1;

    if (!isEmpty(stack)) {
        result = stack->head->value;
        StackElement *tmp = stack->head;
        stack->head = stack->head->next;
        delete tmp;
    }

    return result;
}

void deleteStack(Stack *stack) {
    while (!isEmpty(stack))
        pop(stack);
    delete stack;
}
