#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char exp[100];
    char stack[100];
    int top = -1;

    cout << "Enter an expression: ";
    cin >> exp;

    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stack[++top] = exp[i];
        } 
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                cout << "Not Balanced";
                return 0;
            }
            char open = stack[top--];
            if ((exp[i] == ')' && open != '(') ||
                (exp[i] == '}' && open != '{') ||
                (exp[i] == ']' && open != '[')) {
                cout << "Not Balanced";
                return 0;
            }
        }
    }

    if (top == -1)
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}