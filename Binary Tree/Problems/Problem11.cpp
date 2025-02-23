// Check if a given tree is a Sum Tree or not
// A Sum Tree is a Binary Tree where the value of a node is equal to the sum of the values of its left and right subtree.
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Should return true if tree is Sum Tree, else false
// Helper function that returns {isSumTree, sum of subtree}
pair<bool, int> isSumTreeHelper(Node* root) {
    if (root == NULL)
        return {true, 0};  // Base case: empty tree is a Sum Tree, sum is 0
    
    if (!root->left && !root->right)
        return {true, root->data}; // Leaf node: sum is its own value

    // Recursively check left and right subtrees
    auto left = isSumTreeHelper(root->left);
    auto right = isSumTreeHelper(root->right);

    // Check if current node follows the Sum Tree property
    bool isSumTree = left.first && right.first && (root->data == left.second + right.second);

    return {isSumTree, root->data + left.second + right.second}; 
}

bool isSumTree(Node* root) {
    return isSumTreeHelper(root).first;
}

int main() {
    Node* root1 = buildTree("26 10 3 6 4 3 N");
    cout << isSumTree(root1) << endl; // Output: 1
    Node* root2 = buildTree("10 20 30 10 10");
    cout << isSumTree(root2) << endl; // Output: 0
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree.