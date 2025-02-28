// Construct Tree from Inorder and Level Order Traversal
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int n;
    cin>>n;
    int inorder[n], levelOrder[n];
    for(int i=0;i<n;i++)
        cin>>inorder[i];
    for(int i=0;i<n;i++)
        cin>>levelOrder[i];
    Node *root = buildTree(inorder, levelOrder, 0, n-1,n);
    printPreorder(root);
    return 0;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    if(iStart>iEnd)
        return NULL;
    if(iStart==iEnd-1 || iStart==iEnd)
        return new Node(levelOrder[iStart]);
    
    Node* root = new Node(levelOrder[iStart]);
    if(2*iStart+1<=iEnd){
        root->left = buildTree(inorder,levelOrder,2*iStart+1,iEnd,n);
    }
    if(2*iStart+2<=iEnd){
        root->right = buildTree(inorder,levelOrder,2*iStart+2,iEnd,n);
    }
    return root;
}

// Time Complexity: O(n)
// Space Complexity: O(n)