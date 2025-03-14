//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

//Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],{0,i}});
    }
    
    vector<int>res;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        res.push_back(p.first);
        if(p.second.first+1<arr[p.second.second].size()){
            pq.push({arr[p.second.second][p.second.first+1],{p.second.first+1,p.second.second}});
        }
    }
    return res;
}

int main()
{
	vector<vector<int>> arr(3);
    arr[0] = {1, 2, 3, 4};
    arr[1] = {2, 3, 4, 5};
    arr[2] = {5, 6, 7, 8};
    vector<int> output = mergeKArrays(arr, 3);
    printArray(output, 12);
	return 0;
}

// Time Complexity: O(NlogK)
// Space Complexity: O(K)