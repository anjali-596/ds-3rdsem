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
        cout << endl;
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

    int middle(){
        Node* temp = head;
        int count = 0;

        if (temp == NULL) return -1;

        while (temp != NULL){
            count++;
            temp = temp->next;
        }
        temp = head;
        for (int i=0; i<count/2; i++){
            temp = temp->next;
        }
        return temp->data;

    }
};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(1);
    ll.push_back(5);
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(1);

    ll.print_ll();
    cout << "Middle element:" << ll.middle() << endl;
}