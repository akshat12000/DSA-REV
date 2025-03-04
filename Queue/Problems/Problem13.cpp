// C++ program to find the next right node of a given key
// in a binary tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

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

Node *nextRight(Node *root, int key)
{
    Node *nullNode = new Node(-1);
    if(root==NULL)
    return nullNode;
    queue<pair<Node*,int>>q;
    q.push({root,1});
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        if(x.first->data==key)
            return (q.empty() || q.front().second!=x.second)?nullNode:q.front().first;
        if(x.first->left)
            q.push({x.first->left,x.second+1});
        if(x.first->right)
            q.push({x.first->right,x.second+1});
    }
    return nullNode;
}

int main()
{
    Node *root = buildTree("10 2 6 8 5 3 2 1 N 3 4 5");
    int key = 2;
    Node *res = nextRight(root, key);
    if(res->data==-1)
        cout<<"No next right node found";
    else
        cout << res->data;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)