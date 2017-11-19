#include <iostream>

using namespace std;

void input(char a[]){
    cin >> a;
}

bool balance(char a[], int aSize){
    int k = 0;
    if (a[0] == '('){
            k++;
    }
    else {
        k--;
    }

    int h = 1;
    while ((h < aSize) && (k >= 0)){

        if (a[h] == '('){
                k++;
        }
        if (a[h] == ')'){
                k--;
        }

        h++;
    }
    return (k == 0);
}

int main()
{
    const int length = 100;
    char brackets[length];
    bool result = false;

    cout << "Enter a bracket sequence : " << endl;
    input(brackets);
    result = balance(brackets,length);

    if (result){
        cout << "A correct bracket sequence." << endl;
    }
    else {
        cout << "Wrong bracket sequence." << endl;;
    }

    return 0;
}
