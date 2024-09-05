#include <iostream>
using namespace std;

int main() {
    char* a = new char[6] {"hello"};

    a[5] = '\0';

    cout << *a++;
    cout << *a++;
    cout << *a++;
    cout << a++;
    cout << a++;
    cout << *a++;

}

