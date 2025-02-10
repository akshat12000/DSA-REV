// Index range of subarray with given sum
#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target) {
    vector<int> ans;
    int i=0,j=0;
    int n = arr.size();
    int sum = 0;
    while(i<n && j<n)
    {
        if(sum==target){
            ans.push_back(i+1);
            ans.push_back(j);
            return ans;
        }
        while(j<n&&sum<target){
            sum+=arr[j];
            j++;
        }
        while(i<n&&sum>target){
            sum-=arr[i];
            i++;
        }
    }
    if(sum == target){
        ans.push_back(i+1);
        ans.push_back(j);
        return ans;
    }
    ans.push_back(-1);
    return ans;
}

int main() {
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>res = subarraySum(arr,target);
    for(auto x:res){
        cout<<x<<" ";
    }
    return 0;
}