// C++ program to check if a given Binary
// Tree is symmetric
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Recursive helper function to check if two subtrees are mirror images
bool isMirror(Node* leftSub, Node* rightSub) {
    
    // Both are null, so they are mirror images
    if (leftSub == nullptr && rightSub == nullptr) 
        return true;
    
    // One of them is null, so they aren't mirror images
    if (leftSub == nullptr || rightSub == nullptr || 
                    leftSub->data != rightSub->data) {
        return false;
    }
    
    // Check if the subtrees are mirrors
    return isMirror(leftSub->left, rightSub->right) &&
           isMirror(leftSub->right, rightSub->left);
}

bool isSymmetric(Node* root) {
    
    // If tree is empty, it's symmetric
    if (root == nullptr) 
        return true;
    
    // Check if the left and right subtrees are 
      // mirrors of each other
    return isMirror(root->left, root->right);
}

int main() {
    
    // Creating a sample symmetric binary tree
    //        1
    //       / \
    //      2   2
    //     / \ / \
    //    3  4 4  3
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if(isSymmetric(root))
        cout << "true";
      else 
        cout << "false";
    
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(h) where h is the height of the binary tree