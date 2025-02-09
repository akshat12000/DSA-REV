// 2 Pointer Approach to find a pair of elements in an array whose sum is equal to a given number

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];

    int sum;
    cin>>sum;
    bool found = false;
    sort(A.begin(), A.end());

    int i=0, j=n-1;
    while(i<j)
    {
        if(A[i]+A[j]==sum)
        {
            found = true;
            break;
        }
        else if(A[i]+A[j]<sum)
            i++;
        else
            j--;
    }
    if(found)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    return 0;
}