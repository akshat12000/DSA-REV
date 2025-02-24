// C++ code to find level of a Node in Binary Tree
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to find the level of the target key
int getLevel(Node* root, int target) {
    if (root == nullptr) {
        return -1; 
    }

    // Create a queue for level-order 
  // traversal
    queue<Node*> q;
    q.push(root);
    int level = 1;

    while (!q.empty()) {
        int size = q.size();

        // Process all nodes at the current level
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            // Check if the current node matches the target
            if (curr->data == target) {
                return level;
            }

            // Push the left and right children to the queue
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }

        level++;
    }

    return -1;
}

int main() {
      
    // Creating a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \ / \
    //   4  5 6  7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int target = 5;
    cout << getLevel(root, target);

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)