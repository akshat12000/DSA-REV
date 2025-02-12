// C++ program to find the smallest
// window containing all characters
// of a pattern.
#include <bits/stdc++.h>
using namespace std;


int findSubString(string& s) {
    unordered_set<char>st;
    map<char,int>mp;
    int n = s.length();
    for(int i=0;i<n;i++){
        st.insert(s[i]);
    }
    int limit = st.size();
    int len = INT_MAX;
    int i=0;
    for(int j=0;j<n;j++){
        mp[s[j]]++;
        while(i<n && mp.size()==limit){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                len = min(j-i+1,len);
                mp.erase(s[i]);
            }
            i++;
        }
    }
    return len;
}

int main() {
    string str = "aabcbcdbca";
    cout << "Smallest window containing all distinct"
            " characters is: "
         << findSubString(str);
    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(n)