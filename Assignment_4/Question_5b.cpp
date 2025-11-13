#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.empty() ? -1 : q.front();
    }

    bool empty() {
        return q.empty();
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