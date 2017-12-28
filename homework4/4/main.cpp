#include <iostream>
#include "stack.h"

using namespace std;

void inputCharacter(){
    char character = ' ';
    Stack *stack = createStack();
    cin.get(character);

    while (character != '\n') {
        if (character >= '0' && character <= '9')
            push(stack,character - '0');
        switch (character) {
            case '+' : push(stack,pop(stack) + pop(stack)); break;
            case '-' : push(stack,pop(stack) - pop(stack)); break;
            case '*' : push(stack,pop(stack) * pop(stack)); break;
            case '/' : push(stack,pop(stack) / pop(stack)); break;
        }
        cin.get(character);
    }

    cout << "\n";
    cout <<"The answer is: " << pop(stack);

    deleteStack(stack);
}

int main(){
    cout << "Enter expression: ";
    inputCharacter();
    return 0;
}
