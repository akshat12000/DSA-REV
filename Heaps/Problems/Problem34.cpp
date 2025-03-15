// C++ to find sum of all elements between two kth smallest elements
#include<bits/stdc++.h>
using namespace std;

long long KThSmallest(long long A[], long long N, long long K){
    priority_queue<int>pq;
    for(int i=0;i<N;i++){
        pq.push(A[i]);
        if(pq.size()>K){
            pq.pop();
        }
    }
    return pq.top();
}
long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
{
    // Your code goes here
    int num1 = KThSmallest(A,N,K1);
    int num2 = KThSmallest(A,N,K2);
    
    long long sum = 0;
    for(int i=0;i<N;i++){
        if(A[i]>num1 && A[i]<num2){
            sum+=A[i];
        }
    }
    return sum;
}

int main()
{
    long long N = 7;
    long long A[] = {20, 8, 22, 4, 12, 10, 14};
    long long K1 = 3, K2 = 6;
    cout<<sumBetweenTwoKth(A,N,K1,K2);
	return 0;
}

// Time Complexity: O(NlogK)
// Space Complexity: O(K)