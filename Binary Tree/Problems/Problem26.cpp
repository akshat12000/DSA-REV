// C++ program to print postorder traversal
// using stack
#include <bits/stdc++.h>
using namespace std;

// A tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// An iterative function to do postorder 
// traversal of a binary tree
vector<int> postOrderIterative(Node* root) {
    stack<Node*> s;
    vector<int> post;
    unordered_map<Node*, int> vis;

    s.push(root);

    while (!s.empty()) {
        vis[s.top()] = 1;

        if (s.top()->left && !vis[s.top()->left]) {
            s.push(s.top()->left);
            continue;
        }

        if (s.top()->right && !vis[s.top()->right]) {
            s.push(s.top()->right);
            continue;
        }

        post.push_back(s.top()->data);
        s.pop();
    }

    return post;
}

// Driver program to test above functions
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printf("Post order traversal of binary tree is:\n[");
    vector<int> postOrderList = postOrderIterative(root);
    for (auto it : postOrderList)
        cout << it << " ";
    printf("]");
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)