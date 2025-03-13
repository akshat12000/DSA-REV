// c++ program to find k most
// frequent element using max heap
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to find  k numbers with most occurrences
vector<int> topKFrequent(vector<int> &arr, int k) {

    // unordered_map 'mp' implemented as frequency hash
    // table
    unordered_map<int, int> mp;
    for (int val: arr)
        mp[val]++;

    priority_queue<pair<int, int>, 
    vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (pair<int, int> entry : mp) {
        pq.push({entry.second, entry.first});
        if (pq.size() > k)
            pq.pop();
    }

    // store the result
    vector<int> res(k);

    for (int i = k-1; i >= 0; i--) {
        res[i] = pq.top().second;
        pq.pop();
    }
    
    return res;
}

int main() {

    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1};
    int k = 2;
    vector<int> res = topKFrequent(arr, k);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}

// Time complexity: O(N log K) for each element
// Space complexity: O(N) for hash table and priority queue