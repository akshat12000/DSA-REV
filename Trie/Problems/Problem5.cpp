// C++ program to find shortest unique 
// prefix for every word in a given list
#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    vector<Node*> children;
    int freq;
    char ch;

public:
    Node(char x) {
        freq = 0;
        ch = x;
        children = vector<Node*>(26, nullptr);
    }

    // Insert a word into the Trie
    void insert(string& word) {
        Node* curr = this;
        for(char c : word) {
            if(curr->children[c-'a'] == nullptr) {
                curr->children[c-'a'] = new Node(c);
            }
            curr = curr->children[c-'a'];
            curr->freq++;
        }
    }

    // Find the ending index of minimum 
    // unique prefix for given word
    int findPrefix(string& word) {
        Node* curr = this;
        for(int i = 0; i < word.length(); i++) {
            curr = curr->children[word[i]-'a'];
            // If frequency is 1, we found the unique prefix
            if(curr->freq == 1) {
                return i;
            }
        }
        return word.length() - 1;
    }
    
    void deleteTrie(Node* root) {
        if (root==nullptr) return;
        
        for (int i=0; i<26; i++) {
            deleteTrie(root->children[i]);
            delete root->children[i];
        }
    }
};

vector<string> findPrefixes(vector<string>& arr) {
    int n = arr.size();
    
    // Create root node of Trie
    Node* root = new Node('*');
    
    // Insert all words into the Trie
    for(int i=0; i<n; i++) {
        root->insert(arr[i]);
    }
    
    // Vector to store result prefixes
    vector<string> result;
    
    // Find minimum unique prefix for each word
    for(int i=0; i<n; i++) {
        string word = arr[i];
        
        // Get ending index of minimum prefix
        int endIndex = root->findPrefix(word);
        
        // Add substring from start to endIndex to result
        result.push_back(word.substr(0, endIndex + 1));
    }
    
    // Free up the trie space.
    root->deleteTrie(root);
    
    return result;
}

int main() {
    vector<string> arr = {"zebra", "dog", "duck", "dove"};
    vector<string> ans = findPrefixes(arr);
    for (string val: ans) {
        cout << val << " ";
    }
    cout << endl;
}

// Time Complexity: O(N * M) where N is the number of words and M is the length of the longest word.
// Auxiliary Space: O(N * M) where N is the number of words and M is the length of the longest word.