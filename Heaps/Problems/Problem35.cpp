// min sum formed by adding two numbers formed by digits of an array
#include<bits/stdc++.h>
using namespace std;

long long int minSum(int arr[], int n)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    long long int num1=0,num2=0;
    int i=0;
    while(!pq.empty()){
        if(i%2==0){
            num1=num1*10+pq.top();
        }else{
            num2=num2*10+pq.top();
        }
        pq.pop();
        i++;
    }
    return num1+num2;
}

int main()
{
    int arr[] = {6, 8, 4, 5, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minSum(arr, n);
    return 0;
}

// Time Complexity: O(NlogN)
// Space Complexity: O(N)