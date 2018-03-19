#include <iostream>
#include "stack.h"

using namespace std;

int operatorPriority(char operation)
{
    if (operation == '*' || operation == '/')
        return 2;

    if (operation == '+' || operation == '-')
        return 1;

    return 0;
}

bool isOperator(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

bool isDigit(char symbol)
{
    return '0' <= symbol && symbol <= '9';
}

void processOperator(Stack *operators, Stack *result, char currentSymbol)
{
    if (!isEmpty(operators))
    {
        char currentOperator = popChar(operators);
        while (operatorPriority(currentSymbol) <= operatorPriority(currentOperator) && !isEmpty(operators))
        {
            pushChar(result, currentOperator);
            currentOperator = popChar(operators);
        }

        if (operatorPriority(currentSymbol) <= operatorPriority(currentOperator))
            pushChar(result, currentOperator);
        else
            pushChar(operators, currentOperator);
    }
    pushChar(operators, currentSymbol);
}

void processSymbol(Stack *operators, Stack *result, char currentSymbol)
{
    if (isDigit(currentSymbol))
        pushChar(result, currentSymbol);

    if (currentSymbol == '(')
        pushChar(operators, currentSymbol);

    if (currentSymbol == ')')
    {
        char currentOperator = popChar(operators);
        while (currentOperator != '(')
        {
            pushChar(result, currentOperator);
            currentOperator = popChar(operators);
        }
    }

    if (isOperator(currentSymbol))
        processOperator(operators, result, currentSymbol);
}

int main()
{
    Stack *operators = createStack();
    Stack *result = createStack();

    cout << "Enter an expression: " << endl;

    char currentSymbol = '\0';
    cin.get(currentSymbol);
    while (currentSymbol != '\n')
    {
        processSymbol(operators, result, currentSymbol);
        cin.get(currentSymbol);
    }

    while (!isEmpty(operators))
        pushChar(result, popChar(operators));

    int outputStringLength = length(result);
    char *outputString = toString(result);

    cout << "Postfix form: ";
    for (int i = 0; i < outputStringLength; i++)
        cout << outputString[i] << " ";

    delete[] outputString;
    deleteStack(operators);
    deleteStack(result);

    return 0;
}
