#include <iostream>
using namespace std;

// Node for Doubly Linked List
struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
    
    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Node for Circular Linked List  
struct CLLNode {
    int data;
    CLLNode* next;
    
    CLLNode(int val) : data(val), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DLLNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    
    void insertFirst(int val) {
        DLLNode* newNode = new DLLNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
    void insertLast(int val) {
        DLLNode* newNode = new DLLNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DLLNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    void insertAfter(int afterVal, int val) {
        DLLNode* temp = head;
        while (temp && temp->data != afterVal) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        DLLNode* newNode = new DLLNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
    
    void deleteNode(int val) {
        if (!head) return;
        
        DLLNode* temp = head;
        while (temp && temp->data != val) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
    
    bool search(int val) {
        DLLNode* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }
    
    void display() {
        DLLNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularLinkedList {
private:
    CLLNode* head;
public:
    CircularLinkedList() : head(nullptr) {}
    
    void insertFirst(int val) {
        CLLNode* newNode = new CLLNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CLLNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    
    void insertLast(int val) {
        CLLNode* newNode = new CLLNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CLLNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    
    void insertAfter(int afterVal, int val) {
        if (!head) return;
        
        CLLNode* temp = head;
        do {
            if (temp->data == afterVal) {
                CLLNode* newNode = new CLLNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }
    
    void deleteNode(int val) {
        if (!head) return;
        
        CLLNode *curr = head, *prev = nullptr;
        do {
            if (curr->data == val) {
                if (curr == head && curr->next == head) {
                    head = nullptr;
                } else if (curr == head) {
                    CLLNode* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Node not found!\n";
    }
    
    bool search(int val) {
        if (!head) return false;
        
        CLLNode* temp = head;
        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
    
    void display() {
        if (!head) return;
        
        CLLNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, listType, val, afterVal;
    
    do {
        cout << "\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nChoose list type: ";
        cin >> listType;
        
        if (listType == 3) break;
        
        cout << "\n1. Insert First\n2. Insert Last\n3. Insert After\n4. Delete\n5. Search\n6. Display\n7. Back to Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                if (listType == 1) dll.insertFirst(val);
                else cll.insertFirst(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                if (listType == 1) dll.insertLast(val);
                else cll.insertLast(val);
                break;
            case 3:
                cout << "Enter value to insert after: "; cin >> afterVal;
                cout << "Enter value: "; cin >> val;
                if (listType == 1) dll.insertAfter(afterVal, val);
                else cll.insertAfter(afterVal, val);
                break;
            case 4:
                cout << "Enter value to delete: "; cin >> val;
                if (listType == 1) dll.deleteNode(val);
                else cll.deleteNode(val);
                break;
            case 5:
                cout << "Enter value to search: "; cin >> val;
                if (listType == 1) 
                    cout << (dll.search(val) ? "Found" : "Not Found") << endl;
                else
                    cout << (cll.search(val) ? "Found" : "Not Found") << endl;
                break;
            case 6:
                if (listType == 1) dll.display();
                else cll.display();
                break;
        }
    } while (choice != 7);
    
    return 0;
}