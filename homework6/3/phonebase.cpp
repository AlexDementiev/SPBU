#include "phonebase.h"
#include <fstream>
#include <iostream>

using namespace std;

struct BaseElement
{
    char *name;
    char *phone;
    BaseElement *next;
};

struct Base
{
    BaseElement *elements;
    int length;
};

void addFromFile(ifstream file, Base *base)
{
    char *name = new char[maxLength];
    char *phone = new char[maxLength];
    file.getline(name, maxLength);
    file.getline(phone, maxLength);
    add(base, name, phone);
}

Base *load()
{
    ifstream file;
    file.open("base.txt");

    Base *base = new Base;
    base->elements = nullptr;
    base->length = 0;

    if (file.is_open()) {
        int numberOfElements = 0;
        file >> numberOfElements;
        file.ignore();
        for (int i = 0; i < numberOfElements; i++) {
            char *name = new char[maxLength];
            char *phone = new char[maxLength];
            file.getline(name, maxLength);
            file.getline(phone, maxLength);
            add(base, name, phone);
        }
        file.close();
    }

    return base;
}

void save(Base *base)
{
    remove("base.txt");

    ofstream file;
    file.open("base.txt");

    file << base->length << endl;

    BaseElement *tmp = base->elements;
    while (tmp != nullptr)
    {
        file << tmp->name << endl << tmp->phone << endl;
        tmp = tmp->next;
    }

    file.close();
}

void clearElement(BaseElement *element)
{
    if (element == nullptr)
        return;

    clearElement(element->next);

    delete[] element->name;
    delete[] element->phone;
    delete element;
}

void clear(Base *base)
{
    clearElement(base->elements);
    delete base;
}

void add(Base *base, char *name, char *phone)
{
    BaseElement *newElement = new BaseElement;
    newElement->name = name;
    newElement->phone = phone;
    newElement->next = base->elements;
    base->elements = newElement;
    base->length++;
}

bool isEqual(char *first, char *second)
{
    int index = 0;
    while (first[index] != '\0' && second[index] != '\0' && first[index] == second[index])
    {
        index++;
    }
    return first[index] == second[index];
}

char *findName(Base *base, char *phone)
{
    BaseElement *tmp = base->elements;
    while (tmp != nullptr && !isEqual(tmp->phone, phone))
    {
        tmp = tmp->next;
    }
    if (tmp == nullptr)
        return "Unknown phone";
    return tmp->name;

}

char *findPhone(Base *base, char *name)
{
    BaseElement *tmp = base->elements;
    while (tmp != nullptr && !isEqual(tmp->name, name))
    {
        tmp = tmp->next;
    }

    if (tmp == nullptr)
        return "Unknown name";
    return tmp->phone;
}
