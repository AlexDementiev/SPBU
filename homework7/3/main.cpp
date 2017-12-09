#include <iostream>
#include <fstream>
#include <expressionTree.h>

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

    return 0;
}
