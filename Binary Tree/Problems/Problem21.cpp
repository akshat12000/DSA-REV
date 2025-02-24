// C++ implementation to check if a binary
// tree is complete by position of null
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

// Function to check if the binary
// tree is complete
bool isCompleteBinaryTree(Node* root) {
    if (root == nullptr) {
        return true;
    }

    queue<Node*> q;
    q.push(root);
    bool nullEncountered = false;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
 
         if (curr == NULL) {
           
            // If we have seen a NULL node, we 
               // set the flag to true
            nullEncountered= true;
        }
        else {
          
            // If that NULL node is not the last node then
            // return false
            if (nullEncountered == true) {
                return false;
            }
          
            // Push both nodes even if 
              // there are null
            q.push(curr->left);
            q.push(curr->right);
        }      
    }

    return true;
}

int main() {
  
    // Representation of Input tree
    //         1
    //        /  \
    //       2    3
    //      / \   /
    //     4   5  6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6); 
    
    if (isCompleteBinaryTree(root)) {
        cout << "True" << endl;
    } 
    else {
        cout << "False" << endl;
    }

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)