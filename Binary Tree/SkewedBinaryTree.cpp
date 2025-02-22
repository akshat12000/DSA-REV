// Left Skewed Binary Tree
#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
	int key;
	struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;

	return (temp);
}

// Driver code
int main()
{
	/*
			 1
		    /
	       2
		  /
		3
	*/
	Node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);

	return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)