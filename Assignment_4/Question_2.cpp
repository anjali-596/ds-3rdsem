#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr, front, rear, capacity;
public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int x = arr[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % capacity;
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
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);
    int choice, value;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: 
                cout << "Enter value: "; cin >> value;
                cq.enqueue(value); break;
            case 2: 
                cout << "Dequeued: " << cq.dequeue() << endl; break;
            case 3: 
                cout << "Front: " << cq.peek() << endl; break;
            case 4: 
                cq.display(); break;
        }
    } while(choice != 5);
    
    return 0;
}