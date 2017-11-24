#include <iostream>
#include <fstream>

using namespace std;

int length(char *string)
{
    int index = 0;
    while (string[index] != '\0')
        index++;

    return index;
}

bool isData(char *string)
{
    if (length(string) == 10)
    {
        int index = 0;
        char currentSymbol = string[index];
        while (index < 10)
        {
            if (currentSymbol == '.' && (index == 2 || index == 5))
            {
                index++;
                continue;
            }

            if (currentSymbol == '.' && !(index == 2 || index == 5))
                return false;

            if (!(currentSymbol >= '0' && currentSymbol <= '9'))
                return false;
            index++;
        }
        return true;
    }

    return false;
}

int main()
{
    char buff[255] = {'\0'};

    ifstream fin("input.txt");
    fin >> buff;

    int day = 32;
    int month = 13;
    int year = 10000;
    while (fin)
    {
        if(isData(buff))
        {
            int newDay = ((int)buff[0] - 48) * 10 + (int)buff[1] - 48;
            int newMonth = ((int)buff[3] - 48) * 10 + (int)buff[4] - 48;
            int newYear = ((int)buff[6] - 48) * 1000 + ((int)buff[7] - 48) * 100 + ((int)buff[8] - 48) * 10 + (int)buff[9] - 48;

            if (newYear < year)
            {
                day = newDay;
                month = newMonth;
                year = newYear;
            }
            else if (newMonth < month && year == newYear)
            {
                day = newDay;
                month = newMonth;
                year = newYear;
            }
            else if (newDay < day && month == newMonth)
            {
                day = newDay;
                month = newMonth;
                year = newYear;
            }

        }
        fin >> buff;
    }

    if (day < 10)
        cout << "0" << day << ".";
    else
        cout << day << ".";

    if (month < 10)
        cout << "0" << month << ".";
    else
        cout << month << ".";

    if (year < 10)
        cout << "000" << year;
    else if (year < 100)
        cout << "00" << year;
    else if (year < 1000)
        cout << "0" << year;
    else
        cout << year;

    return 0;
}
