#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    char postfix[100];
    int stack[100];
    int top = -1;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            stack[++top] = c - '0';
        }
        else {
            int val2 = stack[top--];
            int val1 = stack[top--];
            switch (c) {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
                case '^': stack[++top] = pow(val1, val2); break;
            }
        }
    }

    cout << "Result: " << stack[top];
    return 0;
}