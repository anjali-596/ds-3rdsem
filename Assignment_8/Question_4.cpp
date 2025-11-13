#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (!root) return true;
    
    if (root->data <= minVal || root->data >= maxVal) return false;
    
    return isBSTUtil(root->left, minVal, root->data) && 
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    // Valid BST
    Node* root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(5);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    
    // Invalid BST
    Node* root2 = new Node(3);
    root2->left = new Node(2);
    root2->right = new Node(5);
    root2->left->left = new Node(1);
    root2->left->right = new Node(4); // 4 > 3 (invalid)
    
    cout << "Tree 1 is BST: " << (isBST(root1) ? "Yes" : "No") << endl;
    cout << "Tree 2 is BST: " << (isBST(root2) ? "Yes" : "No") << endl;
    
    return 0;
}