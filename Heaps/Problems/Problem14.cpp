// C++ program to find maximum distinct 
// elements after removing k elements
#include <bits/stdc++.h> 
using namespace std; 
  
// function to find maximum distinct elements 
// after removing k elements 
int maxDistinctNum(vector<int> &arr, int k) {
    
    // Map to store the count of each 
    // value present in the array.
    unordered_map<int,int> map;
    
    for (int val: arr) {
        map[val]++;
    }
    
    // Max heap in order of higher
    // frequency.
    priority_queue<pair<int,int>> pq;
    
    // Traverse the map and value and 
    // its frequency into the heap 
    for (auto p: map) {
        int val = p.first;
        int freq = p.second;
        
        pq.push({freq, val});
    }
    
    int ans = 0;
    
    while (!pq.empty()) {
        
        pair<int,int> top = pq.top();
        pq.pop();
        int val = top.second;
        int freq = top.first;
        
        // Remove min(freq-1, k) occurrences
        // of val
        int toRemove = min(freq-1, k);
        
        // Increment the distinct count.
        ans++;
        
        // Decrement k.
        k -= toRemove;
    }
 
    // If k > 0, we need to remove 
    // k distinct values.
    return ans-k;
    
}

int main()  { 
    vector<int> arr = {5, 7, 5, 5, 1, 2, 2}; 
    int k = 3; 
  
    cout << maxDistinctNum(arr, k) << endl; 
    return 0; 
} 

// Time Complexity: O(N*log(N))
// Space Complexity: O(N)