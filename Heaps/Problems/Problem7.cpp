// C++ program to find the k largest elements in the  
// array using min heap
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Function to find the k largest elements in the array 
vector<int> kLargest(vector<int>& arr, int k) {
    vector<int>res;
    priority_queue<int,vector<int>,greater<int>>pq;
    int n = arr.size();
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() {
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
  
      vector<int> res = kLargest(arr, k);
      for(int ele : res)
          cout << ele << " ";
      
      return 0;
}

// Time Complexity: O(n*log(k))
// Space Complexity: O(k) as we are using a min heap of size k.