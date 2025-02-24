// C++ program to find height of full binary tree
// using preorder
#include <bits/stdc++.h>
using namespace std;

// function to return max of left subtree height
// or right subtree height
int findDepthRec(string& s, int n, int& index) {
    if (index >= n || s[index] == 'l')
        return 0;

    // calc height of left subtree (In preorder
    // left subtree is processed before right)
    index++;
    int left = findDepthRec(s, n, index);

    // calc height of right subtree
    index++;
    int right = findDepthRec(s, n, index);

    return max(left, right) + 1;
}

int findDepth(string& s, int n) {
    int index = 0;
    return findDepthRec(s, n, index);
}

int main() {
    string s = "nlnnlll";

    cout << findDepth(s, s.size())<< endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the binary tree