//
// Merge Sort
// Time Complexity: O(nlogn) in all cases
//

#include<iostream>
using namespace std;

void Merge(int a[], int l, int m, int r)
{
    int n1= m-l+1;
    int n2 = r-m;
    int temp1[n1], temp2[n2];
    for(int i=0;i<n1;i++){
        temp1[i] = a[l+i];
    }
    for(int i=0;i<n2;i++){
        temp2[i] = a[m+1+i];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(temp1[i]<=temp2[j]){
            a[k] = temp1[i];
            i++;
        }
        else{
            a[k] = temp2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k] = temp1[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = temp2[j];
        j++;
        k++;
    }
}


void MergeSort(int a[], int l, int r)
{
    if(l<r){
        int m = l + (r-l)/2;
        MergeSort(a, l, m);
        MergeSort(a, m+1, r);
        // Merge the two parts
        Merge(a, l, m, r);
    }
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    // Merge Sort: Here, what we will do is we will divide the array into two parts and sort them individually
    // then merge them. We will keep on dividing the array until we get single element in the array.
    // Then we will merge them in sorted order.
    MergeSort(a, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}