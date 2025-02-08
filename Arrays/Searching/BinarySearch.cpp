#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int key;
    cin>>key;
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(a[mid]==key)
        {
            cout<<mid;
            return 0;
        }
        else if(a[mid]<key)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<"Element not found";
    return 0;
}