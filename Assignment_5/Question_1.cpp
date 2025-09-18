#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;  
    }
    
    void push_front(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = tail = newNode;
            return;
        } else{
            newNode->next = head;
            head = newNode;
            return;
        }
    }

    void print_ll(){
        Node* temp = head;

        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;        
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = tail = newNode;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
            return;
        }
    }

    void pop_front(){
        if( head == NULL){
            return;
        } else {
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }
    }

    void pop_back(){
        if (head == NULL){
            return;
        } else {
            Node* temp = head;
            while (temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;

        }      
    }

    void insert(int val, int pos){
        if(pos<0) return;
        if (pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp == NULL) return;
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void search(int key){
        Node* temp = head;
        int pos = 0;
        while(temp != NULL){
            if(temp->data == key){
                cout << "Element found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found" << endl;    
    }
};


int main(){
    List ll;
    
    cout << "Menu:" << endl;
    cout << "1. Push Front" << endl;
    cout << "2. Push Back" << endl;
    cout << "3. Pop Front" << endl;
    cout << "4. Pop Back" << endl;
    cout << "5. Insert at Position" << endl;
    cout << "6. Search Element" << endl;
    cout << "7. Print Linked List" << endl;
    cout << "8. Exit" << endl;

    int choice, val,pos;

    while(true){
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> val;
                ll.push_front(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                ll.push_back(val);
                break;
            case 3:
                ll.pop_front();
                break;
            case 4:
                ll.pop_back();
                break;
            case 5:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                ll.insert(val, pos);
                break;
            case 6:
                cout << "Enter element to search: ";
                cin >> val;
                ll.search(val);
                break;
            case 7:
                ll.print_ll();
                cout << endl;
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}