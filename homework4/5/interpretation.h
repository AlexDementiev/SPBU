#pragma once

bool isDigit(char symbol);
bool isOperator(char symbol);

void *interpretation(char *expression, char *intermediateState, int size);
