#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < heap.size() && heap[left] > heap[maxIndex]) maxIndex = left;
        if (right < heap.size() && heap[right] > heap[maxIndex]) maxIndex = right;
        
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }
    
    int parent(int i) { return (i-1)/2; }
    int leftChild(int i) { return 2*i + 1; }
    int rightChild(int i) { return 2*i + 2; }
    
public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size()-1);
    }
    
    int pop() {
        if (heap.empty()) return -1;
        
        int result = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return result;
    }
    
    int top() {
        return heap.empty() ? -1 : heap[0];
    }
    
    bool empty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq;
    pq.push(30);
    pq.push(20);
    pq.push(50);
    pq.push(10);
    
    cout << "Priority Queue elements: ";
    while (!pq.empty()) {
        cout << pq.pop() << " ";
    }
    return 0;
}