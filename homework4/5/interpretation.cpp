#include "interpretation.h"
#include "stack.h"


bool isDigit(char symbol)
{
    return '0' <= symbol && symbol <= '9';
}

bool isOperator(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

char character(int value)
{
    switch (value)
    {
        case 1:
            return '*';
        case 2:
            return '/';
        case 11:
            return '+';
        case 12:
            return '-';
    }
}

void balance(Stack *stack, int value, char *string, int *index)
{
    int current = *index;
    while (!isEmpty(stack) && peek(stack) / 10 < value / 10)
    {
        string[current] = character(pop(stack));
        current++;
    }
    *index = current;

    if (value == 22)
        pop(stack);
    else
        push(stack, value);
}

void *interpretation(char *expression, char *intermediateState, int size)
{
    Stack *operators = createStack();
    int currentToken = 0;
    int currentIndex = 0;

    while (currentToken < size)
    {
        if (isDigit(expression[currentToken]))
        {
            intermediateState[currentIndex] = expression[currentToken];
            currentIndex++;
        }

        if (isOperator(expression[currentToken]) || expression[currentToken] == '(' || expression[currentToken] == ')')       {
            switch (expression[currentToken])
            {
                case '*':
                    push(operators, 1); break;
                case '/':
                    push(operators, 2); break;
                case '+':
                    balance(operators, 11, intermediateState, &currentIndex); break;
                case '-':
                    balance(operators, 12, intermediateState, &currentIndex); break;
                case '(':
                    push(operators, 21); break;
                case ')':
                    balance(operators, 22, intermediateState, &currentIndex); break;
            }
        }
        currentToken++;
    }

    while (!isEmpty(operators))
        intermediateState[currentIndex++] = character(pop(operators));
}
