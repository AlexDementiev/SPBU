#pragma once

const int maxLength = 80;

struct Base;

Base *load();
void save(Base *base);
void clear(Base *base);

void add(Base *base, char *name, char *phone);
char *findName(Base *base, char *phone);
char *findPhone(Base *base, char *name);
