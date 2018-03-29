#include <iostream>
#include "ui.h"
#include "core.h"

using namespace std;

void centerPrint(const char *message)
{
    int length = 0;
    while (message[length] != '\0')
        length++;

    for (int i = 0; i < (consoleWidth - length - 1) / 2; i++)
        cout << " ";
    for (int j = 0; j < length; j++)
        cout << message[j];

    cout << endl;
}

void printSeparator(char symbol)
{
    for (int i = 0; i < consoleWidth; i++)
        cout << symbol;
    cout << endl;
}

void rules()
{
    printSeparator(' ');
    centerPrint("RULES");
    printSeparator(' ');
    cout << "There is a number of four unequal ditits." << endl;
    cout << "You can try to guess it." << endl;
    cout << "In a turn you need to enter four-digits number." << endl;
    cout << "Then computer give you numbers of Bulls and Cows." << endl;
    cout << "The number of Cows is a number of matching digits in different positions." << endl;
    cout << "The number of Bulls is a number of matching digits in their right positions." << endl;
    cout << "The game ends when you make rigth guess." << endl;
    printSeparator(' ');
    printSeparator('*');
}

void round()
{
    int *number = getNumber();
    char guess[100] = {'\0'};
    int numberOfAttempts = 0;
    printSeparator(' ');
    cout << "Game starts" << endl;
    printSeparator(' ');

    do {
        cout << "Enter the guess ";
        cin >> guess;

        if (!isCorrect(guess))
        {
            cout << "Your guess is not correct" << endl;
            continue;
        } else {
            cout << numberOfBulls(guess, number) << " Bulls, ";
            cout << numberOfCows(guess, number) << " Cows" << endl;
            numberOfAttempts++;
        }
    } while (numberOfBulls(guess, number) != 4);

    delete[] number;
    cout << "It takes " << numberOfAttempts << " attempts" << endl;
    printSeparator('*');
    printSeparator(' ');
    centerPrint("YOU WIN");
    printSeparator(' ');
    printSeparator('*');
}

void invitation()
{
    printSeparator(' ');
    cout << "Start new game? Type 'Y' (yes) to start: ";
    char YN[100] = {'\0'};
    int length = 0;
    cin >> YN;
    while (YN[length] != '\0')
        length++;

    while ((length == 1) && ((YN[0] == 'Y') || (YN[0] == 'y')))
    {
        round();
        cout << "Start new game? Type 'Y' (yes) to start: ";
        length = 0;
        cin >> YN;
        while (YN[length] != '\0')
            length++;
    }
}

void newGame()
{
    printSeparator('*');
    printSeparator(' ');
    centerPrint("~ BULLS & COWS ~");
    printSeparator(' ');
    printSeparator('*');
    rules();
    invitation();
    printSeparator(' ');
    centerPrint("GOODBYE");
}
