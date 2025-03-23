// C++ Program to find the Longest Common Prefix 
// of the given strings using Trie
#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
      int childCount;
      
    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
  
      TrieNode() {
          children = vector<TrieNode*> (26, nullptr);
          childCount = 0;
          isLeaf = false;
    }
};

// If not present, inserts the key into the trie
// If the key is a prefix of trie node, just mark leaf node
void insert(TrieNode* root, string& key) {
    TrieNode* curr = root;
  
    for (char ch: key) {
        int idx = ch - 'a';
        if (curr->children[idx] == nullptr) {
            curr->children[idx] = new TrieNode();
              curr->childCount++;
        }

        curr = curr->children[idx];
    }

    // mark last node as leaf
    curr->isLeaf = true;
}

// Perform a walk on the trie and return the
// longest common prefix string
string walkTrie(TrieNode *root, string& s) {
    TrieNode* curr = root;
    int i = 0;
    
    while (curr->childCount == 1 && !curr->isLeaf) {
          int idx = s[i] - 'a';
          i++;
        curr = curr->children[idx];
    }
    return s.substr(0, i);
}

// A Function that returns the longest common prefix
// from the array of strings
string longestCommonPrefix(vector<string>& arr) {
    TrieNode *root = new TrieNode();
    
      // Insert all strings to the trie
      for (string& s: arr) 
          insert(root, s);

    // Perform a walk on the trie
    return walkTrie(root, arr[0]);
}

int main() {
    vector<string> arr = {"geeksforgeeks", "geeks",
                           "geek", "geezer"};
  
    cout << longestCommonPrefix(arr) << endl;
    return 0;
}

// Time Complexity: O(N*M), where N is the number of strings and M is the length of the longest string.
// Space Complexity: O(N*M).