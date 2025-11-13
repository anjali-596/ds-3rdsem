#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        return q1.empty() ? -1 : q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top: " << s.top() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Top: " << s.top() << endl;
    
    return 0;
}