#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int> &q) {
    if (q.size() % 2 != 0) {
        cout << "Input even number of elements!\n";
        return;
    }
    
    stack<int> s;
    int half = q.size() / 2;
    
    // Push first half to stack
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }
    
    // Enqueue stack elements back to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    // Dequeue and enqueue first half
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }
    
    // Push first half to stack again
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }
    
    // Interleave
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);
    
    interleaveQueue(q);
    
    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}