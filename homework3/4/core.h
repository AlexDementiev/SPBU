#pragma once

const int numberOfDigits = 4;

int *getNumber();

bool isCorrect(const char *attempt);

int numberOfBulls(const char *attempt, const int *answer);
int numberOfCows(const char *attempt, const int *answer);
