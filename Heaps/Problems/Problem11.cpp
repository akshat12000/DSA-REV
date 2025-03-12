// Huffman Encoding
#include<bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f){
        ch=c;
        freq=f;
        left=right=NULL;
    }
};

// Comparator for Min-Heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;  // Min-Heap: Low frequency has high priority
    }
};

void generateCodes(Node* root, string code, unordered_map<char,string>&mp)
{
    if(root==NULL)  
        return;
        
    if(root->ch!='\0')
        mp[root->ch]=code;
        
    generateCodes(root->left,code+"0",mp);
    generateCodes(root->right,code+"1",mp);
}

vector<string> huffmanCodes(string s,vector<int> f,int N)
{
    vector<string>res;
    priority_queue<Node*,vector<Node*>,Compare>pq;
    for(int i=0;i<N;i++){
        pq.push(new Node(s[i],f[i]));
    }
    unordered_map<char,string>mp;
    
    // building the tree
    while(pq.size()>1){
        Node* l = pq.top();
        pq.pop();
        Node* r = pq.top();
        pq.pop();
        Node *parent = new Node('\0',l->freq+r->freq);
        parent->left = l;
        parent->right = r;
        pq.push(parent);
    }
    
    //construct the map
    generateCodes(pq.top(),"",mp);
    for(int i=0;i<N;i++){
        res.push_back(mp[s[i]]);
    }
    sort(res.begin(),res.end());
    return res;
}

int main(){
    string s = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = s.length();
    vector<string> ans = huffmanCodes(s, f, N);
    for(auto i: ans)
        cout<<i<<" ";
	return 0;
}

// Time Complexity: O(NlogN) where N is the number of characters in the string.
// Space Complexity: O(N) where N is the number of characters in the string. // } Driver Code Ends