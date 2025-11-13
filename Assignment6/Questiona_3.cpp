#include <iostream>
using namespace std;

// DLL Node
struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// CLL Node
struct CLLNode {
    int data;
    CLLNode* next;
    CLLNode(int val) : data(val), next(nullptr) {}
};

int sizeDLL(DLLNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int sizeCLL(CLLNode* head) {
    if (!head) return 0;
    
    int count = 0;
    CLLNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    // Test DLL
    DLLNode* dllHead = new DLLNode(10);
    dllHead->next = new DLLNode(20);
    dllHead->next->prev = dllHead;
    dllHead->next->next = new DLLNode(30);
    dllHead->next->next->prev = dllHead->next;
    
    // Test CLL
    CLLNode* cllHead = new CLLNode(5);
    cllHead->next = new CLLNode(15);
    cllHead->next->next = new CLLNode(25);
    cllHead->next->next->next = cllHead; // Make circular
    
    cout << "DLL Size: " << sizeDLL(dllHead) << endl;
    cout << "CLL Size: " << sizeCLL(cllHead) << endl;
    
    return 0;
}