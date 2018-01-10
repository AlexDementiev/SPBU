#include <iostream>
#include <fstream>
#include "expressiontree.h"

using namespace std;

int main()
{
    ExpressionTree *expression = createTree();

    ifstream fin("input.txt");

    inputTree(expression, fin);
    cout << "Infix form: ";
    printInfixForm(expression);
    cout << "Result: " << calculate(expression) << endl;

    clearTree(expression);
    fin.close();

    clearTree(expression);
    return 0;
}
