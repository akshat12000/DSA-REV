// C++ program to encode a 
// binary tree.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node (int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive pre-order function to 
// encode a binary tree.
void encodeTreeRecur(Node* root, string &s,
                     vector<int> &arr) {
    
    // For null nodes
    if (root == nullptr) {
        s.push_back('0');
        return;
    }
    
    s.push_back('1');
    
    // Store pre-order in array.
    arr.push_back(root->data);
    
    // Apply pre-order to left and 
    // right subtree.
    encodeTreeRecur(root->left, s, arr);
    encodeTreeRecur(root->right, s, arr);
}

pair<string, vector<int>> encodeTree(Node* root) {
    string s = "";
    vector<int> arr;
    
    encodeTreeRecur(root, s, arr);
    
    return make_pair(s, arr);
}

int main() {
    
    // Binary tree 
    //           10
    //        /     \  
    //      20       30  
    //     /  \        \
    //   40    50       70
    Node* root = new Node(10);     
    root->left = new Node(20);          
    root->right = new Node(30);         
    //root->left->left = new Node(40);   
    //root->left->right = new Node(50);  
    root->right->right = new Node(70);  

    pair<string, vector<int>> ans = encodeTree(root);
    
    cout << ans.first << endl;
    for (auto num: ans.second) 
        cout << num << " ";
    cout << endl;
    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)