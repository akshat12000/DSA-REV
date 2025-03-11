// Find the Kth largest element in an array
#include <bits/stdc++.h>
using namespace std;

// Function to find the kth largest array element
int kthLargest(vector<int> arr, int K){
    int n = arr.size();

    // Create a min heap (priority queue)
    priority_queue<int, vector<int>, greater<int>> pq;

    // Iterate through the array elements
    for (int i = 0; i < n; i++) {

        // Push the current element onto the min heap
        pq.push(arr[i]);

        // If the size of the min heap exceeds K,
        // remove the largest element
        if (pq.size() > K)
            pq.pop();
    }

    // Return the Kth largest element (top of the min heap)
    return pq.top();
}

int main(){
    
    vector<int> arr = { 12, 3, 5, 7, 19 };
    int K = 2;

    cout << kthLargest(arr, K);
    return 0;
}

// Time Complexity: O(N*log(K))
// Space Complexity: O(K)