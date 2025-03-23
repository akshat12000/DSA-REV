// C++ implementation of the problem to count the number of inversions in an array using Trie Data Structure
#include <iostream>
using namespace std;

// Structure of the node
struct Node {
	int count;
	Node* left;
	Node* right;
};

// function to initialize
// new node
Node* makeNewNode()
{
	Node* temp = new Node;
	temp->count = 1;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// Insert element in trie
void insertElement(int num,
				Node* root,
				int& ans)
{
	// Converting the number
	// into binary form
	for (int i = 63; i >= 0; i--) {
		// Checking if the i-th
		// bit ios set or not
		int a = (num & (1 << i));

		// If the bit is 1
		if (a != 0) {
			// if the bit is 1 that means
			// we have to go to the right
			// but we also checks if left
			// pointer exists i.e there is
			// at least a number smaller than
			// the current number already in
			// the trie we add that count
			// to ans
			if (root->left != NULL)
				ans += root->left->count;

			// If right pointer is not NULL
			// we just iterate to that
			// position and increment the count
			if (root->right != NULL) {
				root = root->right;
				root->count += 1;
			}

			// If right is NULL we add a new
			// node over there and initialize
			// the count with 1
			else {
				Node* temp = makeNewNode();
				root->right = temp;
				root = root->right;
			}
		}

		// if the bit is 0
		else {
			// We have to iterate to left,
			// we first check if left
			// exists? if yes then change
			// the root and the count
			if (root->left != NULL) {
				root = root->left;
				root->count++;
			}

			// otherwise we create
			// the left node
			else {
				Node* temp = makeNewNode();
				root->left = temp;
				root = root->left;
			}
		}
	}
}

// function to count
// the inversions
int getInvCount(int arr[], int n)
{
	Node* head = makeNewNode();
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		// inserting each element in Trie
		insertElement(arr[i],
					head,
					ans);
	}

	return ans;
}

// Driver Code
int main()
{
	int arr[] = { 8, 4, 2, 1 };
	int n = sizeof(arr) / sizeof(int);

	cout << "Number of inversions are : "
		<< getInvCount(arr, n);
	return 0;
}

// Time Complexity: O(N * M) where N is the number of elements in the array and M is the number of bits in the number.
// Auxiliary Space: O(N * M) where N is the number of elements in the array and M is the number of bits in the number.