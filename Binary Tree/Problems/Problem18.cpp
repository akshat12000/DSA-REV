// C++ program to find if there is a subtree with
// given sum
#include <iostream>
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

// Function to calculate the sum of the subtree rooted at the given node
int subtreeSum(Node* root, int& foundSum, int target) {
  
    // Base case: If the node is NULL, return 0
    if (root == nullptr)
        return 0;

    // Calculate the sum of the current subtree
    int currentSum = root->data + 
                    subtreeSum(root->left, foundSum, target) + 
                    subtreeSum(root->right, foundSum, target);

    // If the current subtree sum matches the target, 
    // set foundSum to 1
    if (currentSum == target) {
        foundSum = 1;
    }

    // Return the current subtree sum
    return currentSum;
}

// Function to check if there is a subtree with the given sum
bool hasSubtreeWithGivenSum(Node* root, int sum) {
    int foundSum = 0;

    // Traverse the tree and check for the target sum
    subtreeSum(root, foundSum, sum);

    // Return true if a subtree with the given sum was found
    return foundSum == 1;
}

int main() {
  
    // Creating the given binary tree
    //        1
    //       / \
    //      3   6
    //     / \   /
    //    5   9 8

    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(5);
    root->left->right = new Node(9);
    root->right->left = new Node(8);

    if(hasSubtreeWithGivenSum(root, 17)) {
      cout << "True";
    }
      else cout << "False";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(h) where h is the height of the tree