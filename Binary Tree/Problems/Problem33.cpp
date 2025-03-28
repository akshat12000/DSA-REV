// Spiral Traversal of Tree
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

vector<int> findSpiral(Node* root) {
    queue<Node*>q;
    q.push(root);
    bool isEven=true;
    stack<int>st;
    vector<int>res;
    while(!q.empty())
    {
        int x = q.size();
        if(isEven)
        {
            for(int i=0;i<x;i++)
            {
                auto p = q.front();
                q.pop();
                st.push(p->data);
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            while(!st.empty()){
                res.push_back(st.top());
                st.pop();
            }
            isEven=false;
        }else{
            for(int i=0;i<x;i++)
            {
                auto p = q.front();
                q.pop();
                res.push_back(p->data);
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            isEven=true;
        }
    }
    return res;
}

int main() {
    Node* root = buildTree("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15");
    vector<int> res = findSpiral(root);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)