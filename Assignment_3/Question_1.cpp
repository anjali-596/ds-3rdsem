#include <iostream>
using namespace std;

#define MAXLEN 5

class Stack{
	int arr[MAXLEN];
	int top;
	
public:
		Stack(){ top = -1; }
		
		bool isEmpty() {
			return top == -1;
		} 
		
		bool isFull() {
			return top == MAXLEN-1;
		}
		
		void push(int x){
			if (isFull()){
				cout << "Stack Overflow" << endl;
				return;
			}
			arr[++top] = x;
			cout << x << "pushed into stack" << endl;
		}
		
		void pop(){
			if (isEmpty()){
				cout << "Stack Unmderflow" << endl;
				return;
			}
			cout << arr[top--] << "popped from stack" << endl;
		}
		
		void peek() {
			if (isEmpty()){
				cout << "Stack is empty" << endl;
				return;
			}
			cout << "top element: " << arr[top] << endl;
		}
		
		void display(){
			if (isEmpty()){
				cout << "Stack is empty" << endl;
				return;
			}
			cout << "stack elements: ";
			for (int i = top; i>= 0; i--){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	
};

int main(){
	Stack s;
	int choice,value;
	
	while(1){
		cout << "Stack Menu:" << endl;
		cout << "1) Push"  << endl;
		cout << "2) Pop" << endl;
		cout << "3) Peek" << endl;
		cout << "4) Display" << endl;
		cout << "5) check Empty" << endl;
		cout << "6) checkFull" << endl;
		cout << "7) exit" << endl;
		
		cout << "enter your choice: " << endl;
		cin>>choice;
		
		switch(choice) {
			case 1:
				cout << "Enter a value:" << endl;
				cin >> value;
				s.push(value);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.peek();
				break;
			case 4:
				s.display();
				break;
			case 5:
				if (s.isEmpty()) cout << "Stack is Empty" << endl;
				else cout << "Stack is not empty"<< endl;
				break;
			case 6:
				if (s.isFull()) cout << "Stack is Full " << endl;
				else cout << "Stack is not Full" << endl;
				break;
			case 7:
				return 0;
			default:
				cout << "Invalid input!!" << endl;
				
		}
	}
}