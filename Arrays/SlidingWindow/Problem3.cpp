// Longest Subarray with Sum K
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int pre_sum=0;
    int res = 0;
    int n = arr.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        pre_sum +=arr[i];
        
        if(pre_sum == k){
            res = i+1;
        }
        
        if(mp.find(pre_sum-k)!=mp.end()){
            res = max(res, i-mp[pre_sum-k]);
        }
        
        if(mp.find(pre_sum)==mp.end()){
            mp[pre_sum] = i;
        }
    }
    return res;
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
    int res = longestSubarray(arr,k);
    cout<<res<<"\n";
    return 0;
}