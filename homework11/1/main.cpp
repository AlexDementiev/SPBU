#include <iostream>

bool isDigit(char symbol)
{
    return '0' <= symbol && symbol <= '9';
}

bool isEndOfString(char symbol)
{
    return symbol == '\n';
}

int main()
{
    enum {start, afterSign, integerPart, afterDot, digitAfterDot, afterE, afterESign, digitAfterE, fail} status;
    status = start;

    std::cout << "Enter string: ";
    char symbol = std::cin.get();

    while (!isEndOfString(symbol))
    {
        switch (status)
        {
        case start:
            if (symbol == '+' || symbol == '-')
                status = afterSign;
            else if (isDigit(symbol))
                status = integerPart;
            else
                status = fail;
            break;
        case afterSign:
            if (isDigit(symbol))
                status = integerPart;
            else
                status = fail;
            break;
        case integerPart:
            if (isDigit(symbol))
                status = integerPart;
            else if (symbol == '.')
                status = afterDot;
            else if (symbol == 'E')
                status = afterE;
            else status = fail;
            break;
        case afterDot:
            if (isDigit(symbol))
                status = digitAfterDot;
            else
                status = fail;
            break;
        case digitAfterDot:
            if (isDigit(symbol))
                status = digitAfterDot;
            else if (symbol == 'E')
                status = afterE;
            else
                status = fail;
            break;
        case afterE:
            if (symbol == '+' || symbol == '-')
                status = afterESign;
            else if (isDigit(symbol))
                status = digitAfterE;
            else status = fail;
            break;
        case afterESign:
            if (isDigit(symbol))
                status = digitAfterE;
            else
                status = fail;
            break;
        case digitAfterE:
            if (!isDigit(symbol))
                status = fail;
            break;
        }

        symbol = std::cin.get();
    }



    if (status == integerPart || status == digitAfterDot || status == digitAfterE)
        std::cout << "This is the double real number.\n";
    else
        std::cout << "This is not the double real number.\n";

    return 0;
}
