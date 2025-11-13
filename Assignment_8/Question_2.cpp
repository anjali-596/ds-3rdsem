#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// (a) Search - Recursive
Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// (a) Search - Non-recursive
Node* searchIterative(Node* root, int key) {
    while (root && root->data != key) {
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

// (b) Maximum element
Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

// (c) Minimum element
Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// (d) In-order successor
Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right) return findMin(node->right);
    
    Node* successor = nullptr;
    while (root) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    
    cout << "Min: " << findMin(root)->data << endl;
    cout << "Max: " << findMax(root)->data << endl;
    
    Node* searchResult = searchRecursive(root, 40);
    cout << "Search 40: " << (searchResult ? "Found" : "Not found") << endl;
    
    Node* successor = inorderSuccessor(root, root->left);
    cout << "Successor of 30: " << (successor ? successor->data : -1) << endl;
    
    return 0;
}