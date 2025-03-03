// C++ program to print right view of Binary
// tree using Level order Traversal
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Function to return the right view of the binary tree
vector<int> rightView(Node* root) {
    vector<int> result;

    if (root == nullptr) return result;

    // Queue for level order traversal
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      
        // Number of nodes at current level
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

            // If it's the last node of the current level
            if (i == levelSize - 1) {
                result.push_back(curr->data);
            }

            // Enqueue left child
            if (curr->left != nullptr) {
                q.push(curr->left);
            }

            // Enqueue right child
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
    }

    return result;
}

void printArray(vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
  
    // Representation of the input tree:
    //         1
    //        / \
    //       2   3
    //          / \   
    //         4   5 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = rightView(root);
    
    printArray(result);
    
    return 0;
}

// Time Complexity: O(N), where N is the number of nodes in the binary tree
// Space Complexity: O(N)