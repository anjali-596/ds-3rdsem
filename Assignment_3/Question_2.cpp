#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    char stack[100];
    int top = -1;

    cout << "Enter a string: ";
    cin >> str;

    for (int i = 0; i < strlen(str); i++) {
        stack[++top] = str[i];
    }

    cout << "Reversed string: ";
    while (top != -1) {
        cout << stack[top--];
    }

    return 0;
}