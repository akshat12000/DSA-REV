// Maximum of all subarrays of size K
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum of each subarray of size k.
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    vector<int>ans;
    int n = arr.size();
    deque<int>q(k);
    for(int i=0;i<k;i++){

        // Get rid of smaller element (this is to ensure that front of the queue is always max)
        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(int i=k;i<n;i++){
        ans.push_back(arr[q.front()]);
        
        // Get rid of elements which are out of range
        while(!q.empty() && q.front() <=i-k){
            q.pop_front();
        }

        // Get rid of smaller element (this is to ensure that front of the queue is always max)
        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        
        q.push_back(i);
    }
    ans.push_back(arr[q.front()]);
    return ans;
}

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>res = maxOfSubarrays(arr,k);
    for(auto x:res){
        cout<<x<<" ";
    }
    return 0;
}