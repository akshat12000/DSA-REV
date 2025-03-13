#include <bits/stdc++.h>
using namespace std;

// Function to sort the array 
// according to frequency of elements
vector<int> sortByFreq(vector<int> &arr) {
    int n = arr.size();

    // hash map to store the 
    // frequency of each element
    unordered_map<int, int> mp;

    // store the frequency of each element
    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // to store the frequency 
    // in descending order
    priority_queue<vector<int>> pq;

    // store the frequency and the element
    for(auto i : mp) {

        // storing the negative of element
        // to sor the elements with same
        // frequency in ascending order
        pq.push({i.second, -i.first});
    }

    // to store the answer
    vector<int> ans;

    // push the elements in the answer array
    while(!pq.empty()) {
        int freq = pq.top()[0];
        int ele = -pq.top()[1];
        pq.pop();
        for(int i = 0; i < freq; i++) {
            ans.push_back(ele);
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {5, 5, 4, 6, 4};
    vector<int> ans = sortByFreq(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

// Time complexity: O(N log N) for each element
// Space complexity: O(N) for hash table and priority queue