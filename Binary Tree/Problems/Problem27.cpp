// Inorder Traversal without Recursion and Stack
// Morris Traversal
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void MorrisInorderTraversal(Node* root)
{
    Node* curr = root;
    while(curr !=NULL)
    {
        // If left is NULL, print the current node data and move to right
        if(curr->left == NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        // If left is not NULL
        else
        {
            // Find the inorder predecessor of current
            Node* pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }

            // Make current as right child of its inorder predecessor
            if(pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            // Revert the changes made in if part to restore the original tree
            else
            {
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    // 10
    // / \
    // 5 30
    //   / \
    //  15 20

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);

    MorrisInorderTraversal(root);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)