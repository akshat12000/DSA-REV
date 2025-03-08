// First non-repeating character in a stream
#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string &s) {
    deque<char> dq;         // Track non-repeating characters
    vector<int> freq(26, 0); // Track frequency of characters
    string res = "";

    for (char ch : s) {
        freq[ch - 'a']++;

        if (freq[ch - 'a'] == 1) {
            dq.push_back(ch); // Pehli baar aane wale ko queue mein daalo
        }

        // Queue se repeat hone wale characters hata do
        while (!dq.empty() && freq[dq.front() - 'a'] > 1) {
            dq.pop_front();
        }

        // Result mein pehla non-repeating character ya '#' daalo
        res += dq.empty() ? '#' : dq.front();
    }
    return res;
}

int main() {
    string s = "aabc";
    cout << FirstNonRepeating(s) << endl;
    string s1 = "geeksforgeeksandgeeksquizfor";
    cout << FirstNonRepeating(s1) << endl;
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(n) where n is the size of the string