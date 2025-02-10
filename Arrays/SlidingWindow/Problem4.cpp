// Max Sum Subarray of size K
#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(vector<int>& arr, int k) {
    int sum = 0;
    int ans = INT_MIN;
    int n = arr.size();
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    
    ans = max(ans,sum);
    
    for(int i=k;i<n;i++){
        sum-=arr[i-k];
        sum+=arr[i];
        ans = max(ans,sum);
    }
    
    return ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    int ans = maximumSumSubarray(arr,k);
    cout<<ans<<"\n";
    return 0;
}