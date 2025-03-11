// c++ program to sort k sorted array
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//  function to sorts a nearly sorted array
// where every element is at most
// k positions away from its target position.
void nearlySorted(vector<int>& arr, int k) {
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k+1;i++){
        pq.push(arr[i]);
    }
    int ind=0;
    int n = arr.size();
    for(int i=k+1;i<n;i++){
        arr[ind++]=pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(ind<n&&!pq.empty()){
        arr[ind++]=pq.top();
        pq.pop();
    }
 }

int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    nearlySorted(arr, k);
    for (int x : arr)
        cout << x << ' ';
    return 0;
}

// Time Complexity: O(n*log(k))
// Space Complexity: O(k) as we are using a min heap of size k.