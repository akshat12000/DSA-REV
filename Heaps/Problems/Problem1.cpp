// C program to check whether a given array 
// represents a max-heap or not 
#include <stdio.h> 
#include <limits.h> 

// Returns true if arr[i..n-1] represents a 
// max-heap 
bool isMaxHeap(int arr[], int n)
{
    int i=0;
    while(i<n){
        if(2*i+1<n && arr[i]<arr[2*i+1])
            return false;
        if(2*i+2<n && arr[i]<arr[2*i+2])
            return false;
        i++;
    }
    return true;
}

// Driver program 
int main() 
{ 
	int arr[] = {90, 15, 10, 7, 12, 2, 7, 3}; 
	int n = sizeof(arr) / sizeof(int); 

	isMaxHeap(arr, n)? printf("Yes"): printf("No"); 

	return 0; 
} 

// Time Complexity: O(n) where n is number of nodes in the binary tree.
// Space Complexity: O(1) as no extra space is required.