// C++ program to check if there exist an edge whose
// removal creates two trees of same size
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// To calculate size of tree with given root
int countNodes(Node* root) {
    if (root==nullptr)
        return 0;
    return countNodes(root->left) + 
      countNodes(root->right) + 1;
}

// This function returns size of tree rooted with given
// root. It also set "res" as true if there is an edge
// whose removal divides tree in two halves.
// n is size of tree
int checkRec(Node* root, int n, bool &ans) {
    
    // Base case
    if (root == nullptr)
       return false;
       
    // find the size of current subtree
    int cnt = checkRec(root->left, n, ans) + 
    checkRec(root->right, n, ans) + 1;

    // If unlinking the current subtree from
    // main tree creates two trees of same size,
    // return true.
    if (cnt == n-cnt)
        ans = true;

    // return the size of current
      // subtree.
    return cnt;
}

// This function mainly uses checkRec()
bool check(Node *root) {
    
    // Count total nodes in given tree
    int n = countNodes(root);
    
    bool ans = false;
    
    // Now recursively check all nodes
    checkRec(root, n, ans);
    
    return ans;
}

int main() {
    
    // Binary tree 
    //     5
    //   / \
    //   1   6
    //  /   / \
    // 3   7   4
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(4);

    if (check(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree