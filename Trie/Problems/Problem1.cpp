// Word Break Problem
#include <bits/stdc++.h>
using namespace std;
 
// trie node
struct TrieNode {
    struct TrieNode* children[26];
    
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
    
// Returns new trie node (initialized to NULLs)
struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;
    
    pNode->isEndOfWord = false;
    
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
    
    return pNode;
}
    
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;
    
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
    
        pCrawl = pCrawl->children[index];
    }
    
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
    
// Returns true if key presents in trie, else
// false
bool search(struct TrieNode* root, string key)
{
    struct TrieNode* pCrawl = root;
    
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
    
        pCrawl = pCrawl->children[index];
    }
    
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int WordBreakRec(string A, vector<string>&B, struct TrieNode*root)
{
    int size = A.size();
    // Base case
    if (size == 0)
        return true;
    
    // Try all prefixes of lengths from 1 to size
    for (int i = 1; i <= size; i++) {
        // The parameter for search is str.substr(0, i)
        // str.substr(0, i) which is prefix (of input
        // string) of length 'i'. We first check whether
        // current prefix is in dictionary. Then we
        // recursively check for remaining string
        // str.substr(i, size-i) which is suffix of
        // length size-i
        if (search(root, A.substr(0, i))
            && WordBreakRec(A.substr(i, size - i),B, root))
            return true;
    }
    
    // If we have tried all prefixes and none
    // of them worked
    return false;
}

int wordBreak(string A, vector<string> &B) {
    TrieNode* root = new TrieNode();
    for(auto x:B){
        insert(root,x);
    }
    return WordBreakRec(A,B,root);
}

int main(){
    string A = "myinterviewtrainer";
    vector<string> B = {"trainer", "my", "interview"};
    cout<<wordBreak(A,B)<<endl;
    return 0;
}

// Time Complexity: O(N^2)
// Space Complexity: O(N) where N is the length of the string.