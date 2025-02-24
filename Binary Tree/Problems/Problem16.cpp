// C++ program to check foldable binary tree
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node (int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// function to check if two trees are 
// mirrors 
bool isFoldableRecur(Node* a, Node* b) {
    
    // If both subtrees are null, return 
    // true.
    if (a == nullptr && b == nullptr)
        return true;
        
    // If one of the subtrees is null,
    // return false.
    if (a == nullptr || b == nullptr) 
        return false;
    
    // Compare left subtree of tree 'a' with 
    // right subtree of tree 'b' and compare 
    // right subtree of tree 'a' with left 
    // subtree of tree 'b'.
    return isFoldableRecur(a->left, b->right) 
    &&
    isFoldableRecur(a->right, b->left);
}

// Function to check if a tree is foldable.
bool isFoldable(Node* root) {
    if (root == nullptr) 
        return true;
        
    return isFoldableRecur(root->left, root->right);
}

int main() {
    
    // The constructed binary tree is
    //      1
    //     / \
    //     2 3
    //     \ /
    //     4 5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);

    if (isFoldable(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree