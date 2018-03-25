#pragma once

#include <fstream>

using namespace std;

struct ExpressionTree;

ExpressionTree *createTree();
void clearTree(ExpressionTree *tree);

void inputTree(ExpressionTree *tree, ifstream &file);
int calculate(ExpressionTree *tree);
void printInfixForm(ExpressionTree *tree);
