// C++ program to print inorder traversal
// using stack.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = nullptr; 
        right = nullptr;
    }
};

//Iterative function for inorder tree traversal
vector<int> inOrder(Node* root) {
    vector<int> ans;
    stack<Node*> s;
    Node* curr = root;

    while (curr != nullptr || s.empty() == false) {
        
        // Reach the left most Node of the
        // curr Node
        while (curr != nullptr) {
            
            // Place pointer to a tree node on
            // the stack before traversing
            // the node's left subtree
            s.push(curr);
            curr = curr->left;
        }

        // Current must be NULL at this point
        curr = s.top();
        s.pop();

        ans.push_back(curr->data);

        // we have visited the node and its
        // left subtree.  Now, it's right
        // subtree's turn
        curr = curr->right;
    }
    
    return ans;
}

int main() {
    
    // Constructed binary tree is
    //          1
    //        /   \
    //      2      3
    //    /  \
    //  4     5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = inOrder(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)