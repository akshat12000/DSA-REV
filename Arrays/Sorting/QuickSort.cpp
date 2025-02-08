//
// Quick Sort
// Quick Sort is a divide and conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
// There are many different versions of quickSort that pick pivot in different ways.
// 1. Always pick first element as pivot.
// 2. Always pick last element as pivot.
// 3. Pick a random element as pivot.
// 4. Pick median as pivot.
// The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array
// and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.
//

// Time Complexity: O(nlogn) in average case, O(n^2) in worst case
// Space Complexity: O(logn) in average case, O(n) in worst case


#include<iostream>
using namespace std;

void quickSort(int a[], int l, int r){
    int pivot = a[(l+r)/2];
    int i=l, j=r;
    while(i<=j){
        // element on left side of pivot should be less than pivot
        while(a[i]<pivot){
            i++;
        }
        // element on right side of pivot should be greater than pivot
        while(a[j]>pivot){
            j--;
        }
        // here a[i] is greater than pivot and a[j] is less than pivot, so we will swap them
        if(i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l<j){
        quickSort(a, l, j);
    }
    if(i<r){
        quickSort(a, i, r);
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

    // Quick Sort
    // Approach: we will take a pivot element and place it at its correct position in the array, then sort
    // left and right part of the array recursively.
    quickSort(a, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}