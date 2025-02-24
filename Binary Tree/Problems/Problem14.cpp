// Find if two nodes are cousins in a Binary Tree
// Given the binary Tree and the two nodes say ‘a’ and ‘b’, determine whether the two nodes are cousins of each other or not.
// Two nodes are said to be cousins of each other if they are at the same level of the Binary Tree and have different parents.
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
    Node* root = new Node(stoi(ip[0]));

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
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function to check if two nodes are cousins in a tree
pair<int,Node*> searchParent(Node* root, int key)
{
    if(root==NULL)
        return make_pair(-1,(Node*)NULL);
    queue<pair<Node*,Node*>>q;
    q.push(make_pair((Node*)NULL,root));
    int depth = 0;
    while(!q.empty())
    {
        int sz = q.size();
        for(int i=0;i<sz;i++){
            auto x = q.front();
            q.pop();
            if(x.second->data==key){
                return make_pair(depth,x.first);
            }
            if(x.second->left){
                q.push(make_pair(x.second,x.second->left));
            }
            if(x.second->right){
                q.push(make_pair(x.second,x.second->right));
            }
        }
        depth++;
    }
    return make_pair(-1,(Node*)NULL);
}

bool isCousins(Node* root, int x, int y) {
    pair<int,Node*> px = searchParent(root,x);
    pair<int,Node*> py = searchParent(root,y);
    if(px.first<0 || py.first<0)
        return false;
    // cout<<px.first<<" "<<py.first<<"\n";
    if (px.first==py.first && px.second!=py.second)
        return true;
    return false;
}

int main() {
    Node* root = buildTree("1 2 3 4 5 6 7");
    int x = 4, y = 5;
    if (isCousins(root, x, y))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)