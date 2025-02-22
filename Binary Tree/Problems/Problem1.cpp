// Check whether a binary tree is a full binary tree or not.
// A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes.
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isFullTree (struct Node* root);
int main()
{
	Node* root = buildTree("1 2 3 4 5 6 7");
    if (isFullTree(root))
        cout << "The Binary Tree is a full binary tree\n";
    else
        cout << "The Binary Tree is not a full binary tree\n";
    return 0;
}

bool isFullTree (struct Node* root)
{
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right == NULL)
        return true;
    if(root->left!=NULL && root->right == NULL)
        return false;
    if(root->left==NULL && root->right != NULL)
        return false;
        
    return isFullTree(root->left) && isFullTree(root->right);
}

// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree.