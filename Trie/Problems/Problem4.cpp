// Count Distinct Substrings
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
    string s = "ababa";
    cout << countDistinctSubstring(s) << endl;
    return 0;
}

struct TrieNode {
    map<char,struct TrieNode *> children;
};

//Function to insert string into TRIE.
int insert(struct TrieNode *root, string key)
{
    // code here
    struct TrieNode *node;
    int c;
    
    node = root;
    c = 0;
    for (int i = 0;i < (int)key.length();i++)
    {
        if (node->children.find(key[i]) == node->children.end())
        {
            node->children[key[i]] = new TrieNode;
            c++;
        }
        node = node->children[key[i]];
    }
    return c;
}

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    //Your code here
    struct TrieNode *root;
    int res;
    
    root = new TrieNode;
    res = 1;
    for (int i = 0;i < (int)s.length();i++)
        res += insert(root, s.substr(i));
    return res;
}

// Time Complexity: O(N * M) where N is the length of the string and M is the number of distinct substrings.
// Auxiliary Space: O(N * M) where N is the length of the string and M is the number of distinct substrings.