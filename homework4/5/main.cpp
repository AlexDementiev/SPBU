#include <iostream>
#include "stack.h"

#include "interpretation.h"

using namespace std;

int length(char *string)
{
    int index = 0;
    while (string[index] != '\0')
        index++;
    return index;
}

int operation(int firstOperand, int secondOperand, char operation)
{
    switch (operation)
    {
        case '+':
            return firstOperand + secondOperand;
        case '-':
            return firstOperand - secondOperand;
        case '*':
            return firstOperand * secondOperand;
        case '/':
            return firstOperand / secondOperand;
    }
}

int main()
{
    Stack *stack = createStack();
    int size = 10;
    char *expression = new char[size];
    char *newExpression = new char[size];

    cout << "Enter an expression: " << endl;

    char currentSymbol = '\0';
    cin.get(currentSymbol);
    int index = 0;
    while (currentSymbol != '\n')
    {
        expression[index] = currentSymbol;
        index++;
        cin.get(currentSymbol);
    }

    interpretation(expression, newExpression, index);
    index = length(newExpression);

    currentSymbol = newExpression[0];
    int current = 0;
    while (current < index)
    {
        if (isDigit(currentSymbol))
            push(stack, currentSymbol - '0');

        if (isOperator(currentSymbol))
        {
            int secondOperand = pop(stack);
            int firstOperand = pop(stack);
            push(stack, operation(firstOperand, secondOperand, currentSymbol));
        }
        current++;
        currentSymbol = newExpression[current];
    }

    cout << "Result: " << pop(stack);

    delete[] expression;
    delete[] newExpression;
    deleteStack(stack);

    return 0;
}
