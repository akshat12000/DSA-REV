// C++ program to find if there is a duplicate
// sub-tree of size 2 or more.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    Node *left, *right;
    Node (char x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function which checks all the subtree of size 2 or 
// 3 if they are duplicate.
string dupSubRecur(Node *root, unordered_set<string> &s, 
                   int &ans) {
    
    // For null nodes, 
    if (root == nullptr) return "N";
    
    // For leaf nodes, return its value in string.
    if (root->left==nullptr && root->right==nullptr) {
        return to_string(root->data);
    }
    
    string curr = "";
    curr += to_string(root->data);
    
    // Process the left and right subtree.
    string left = dupSubRecur(root->left, s, ans);
    string right = dupSubRecur(root->right, s, ans);
    
    // If the node is parent to 2 
    // leaf nodes, or 1 leaf node and 1 
    // null node, then concatenate the strings
    if (left != "" && right != "") {
        curr += '*';
        curr += left;
        curr += '*';
        curr += right;
    }
    
    // Otherwise, there is no need 
    // to process this node.
    else {
        return "";
    }
    
    // If this subtree string is already 
    // present in set, set ans to 1.
    if (s.find(curr) != s.end()) {
        ans = 1;
    }
    
    // Else add this string to set.
    else {
        s.insert(curr);
    }
    
    return "";
}

int dupSub(Node *root) {
    int ans = 0;
    unordered_set<string> s;
    
    dupSubRecur(root, s, ans);
    
    return ans;
}

int main() {
    
    //         A
    //       /   \
    //      B     C
    //     / \     \
    //    D   E     B
    //           /   \
    //          D     E
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('B');
    root->right->right->right = new Node('E');
    root->right->right->left = new Node('D');

    if (dupSub(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)