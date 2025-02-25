// C++ program to o find the postorder 
// traversal using 2 Stacks
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

// Function to do post-order traversal
// using two stacks iteratively
vector<int> postOrder(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    // Create two stacks
    stack<Node*> stk1, stk2;

    // Push root to first stack
    stk1.push(root);
    Node* curr;

    // Run while first stack is not empty
    while (!stk1.empty()) {
      
        // Pop from s1 and push it to s2
        curr = stk1.top();
        stk1.pop();
        stk2.push(curr);

        // Push left and right children of the
        // popped node
        if (curr->left) {
            stk1.push(curr->left);
        }
        if (curr->right) {
            stk1.push(curr->right);
        }
    }

    // Collect all elements from second stack
    while (!stk2.empty()) {
        curr = stk2.top();
        stk2.pop();
        result.push_back(curr->data);
    }

    return result;
}

void printArray(const vector<int>& arr) {
    for (int data : arr) {
        cout << data << " ";
    }
    cout << endl;
}

int main() {
  
    // Representation of input binary tree:
    //           1
    //         /   \
    //        2     3
    //      /  \
    //     4    5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);

    printArray(result);

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)