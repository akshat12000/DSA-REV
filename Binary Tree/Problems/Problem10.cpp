// Find the maximum and minimum element in a binary tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void MaxHelper(Node* root, int &res)
{
    if(root==NULL)
        return;
    res = max(res,root->data);
    MaxHelper(root->left,res);
    MaxHelper(root->right,res);
}
void MinHelper(Node* root, int &res)
{
    if(root==NULL)
        return;
    res = min(res,root->data);
    MinHelper(root->left,res);
    MinHelper(root->right,res);
}
int findMax(Node *root)
{
    int res = INT_MIN;
    MaxHelper(root,res);
    return res;
}
int findMin(Node *root)
{
    int res = INT_MAX;
    MinHelper(root,res);
    return res;
}

int main()
{
    Node *root = buildTree("1 2 3 4 5 N 6");
    cout << "Inorder traversal of the tree is: ";
    printInorder(root);
    cout << endl;
    cout << "Maximum element in the tree is: " << findMax(root) << endl;
    cout << "Minimum element in the tree is: " << findMin(root) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree.