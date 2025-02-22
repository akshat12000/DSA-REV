// C++ program for postorder traversals of a binary tree
#include <bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = nullptr;
    }
};

// Function to print postorder traversal
void printPostorder(struct Node* node)
{
    if (node == nullptr)
        return;

    // First recur on left subtree
    printPostorder(node->left);

    // Then recur on right subtree
    printPostorder(node->right);

    // Now deal with the node
    cout << node->data << " ";
}

// Driver code
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Function call
    cout << "Postorder traversal of binary tree is: \n";
    printPostorder(root);

    return 0;
}

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree.