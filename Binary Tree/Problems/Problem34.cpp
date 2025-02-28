// C++ program to print reverse level 
// order traversal using stack and queue
#include <bits/stdc++.h>
using namespace std;

class Node { 
public:
    int data; 
    Node* left; 
    Node* right; 
    Node (int x) {
        data = x;
        left = right = nullptr;
    }
}; 

// Function to print REVERSE 
// level order traversal of a tree
void reverseLevelOrder(Node* root) {
    stack<Node*> st;  
    queue<Node*> q;  
    q.push(root);

    while (!q.empty()) {
        // Dequeue node
        Node* curr = q.front();
        q.pop();
        st.push(curr);

        // Enqueue right child
        if (curr->right)
            q.push(curr->right);

        // Enqueue left child
        if (curr->left)
            q.push(curr->left);
    }

    // Pop all items from stack one by one and print them
    while (!st.empty()) {
        Node* curr = st.top();
        cout << curr->data << " ";
        st.pop();
    }
}

int main() { 
  
    // Create hard coded tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5 
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 

    reverseLevelOrder(root); 

    return 0; 
} 

// Time complexity: O(n)
// Space complexity: O(n)