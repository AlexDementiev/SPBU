#include <iostream>
#include "stack.h"

using namespace std;

bool isOperator(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
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

bool isDigit(char symbol)
{
    return '0' <= symbol && symbol <= '9';
}

int main()
{
    Stack *stack = createStack();
    cout << "Enter an expression in postfix form: " << endl;

    char currentSymbol = '\0';
    cin.get(currentSymbol);
    while (currentSymbol != '\n')
    {
        if (isDigit(currentSymbol))
            pushInt(stack, currentSymbol - '0');

        if (isOperator(currentSymbol))
        {
            int secondOperand = popInt(stack);
            int firstOperand = popInt(stack);
            pushInt(stack, operation(firstOperand, secondOperand, currentSymbol));
        }

        cin.get(currentSymbol);
    }

    cout << "= " << popInt(stack);

    deleteStack(stack);
    return 0;
}
