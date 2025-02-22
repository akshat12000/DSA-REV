// Degenerate Binary Tree: Right Skewed Binary Tree
// A tree is called a degenerate tree if every internal node has one child. Such a tree is also known as a right-skewed binary tree. In a right-skewed binary tree, every internal node has one child, which is the right child. The left child of an internal node is always NULL.
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

// Function to insert nodes on the right side of
// current node
Node* insert(Node* root, int data)
{
	if (root == NULL) {
		root = new Node(data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root;
}

// Function to print tree
void printTree(Node* node)
{
	if (node != NULL) {
		cout << node->data << endl;
		printTree(node->right);
	}
}

// Driver code
int main()
{
	Node* root = NULL;
	root = insert(root, 1);
	insert(root, 2);
	insert(root, 3);
	insert(root, 4);
	insert(root, 5);

	// Function call
	printTree(root);

	return 0;
}

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(n).