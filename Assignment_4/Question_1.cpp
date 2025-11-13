#include <iostream>
using namespace std;

class Queue {
private:
    int *arr, front, rear, capacity;
public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int x = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return x;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q(5);
    int choice, value;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: 
                cout << "Enter value: "; cin >> value;
                q.enqueue(value); break;
            case 2: 
                cout << "Dequeued: " << q.dequeue() << endl; break;
            case 3: 
                cout << "Front: " << q.peek() << endl; break;
            case 4: 
                q.display(); break;
        }
    } while(choice != 5);
    
    return 0;
}
