// CPP program to find three numbers 
// such that sum of two makes the 
// third element in array 
#include <bits/stdc++.h> 
#include <iostream> 
using namespace std; 

// function to perform binary search 
bool search(int sum, int start, int end, int arr[]) 
{ 
	while (start <= end) { 
		int mid = (start + end) / 2; 
		if (arr[mid] == sum) { 
			return true; 
		} 
		else if (arr[mid] > sum) { 
			end = mid - 1; 
		} 
		else { 
			start = mid + 1; 
		} 
	} 
	return false; 
} 

// function to find the triplets 
void findTriplet(int arr[], int n) 
{ 
	// sorting the array 
	sort(arr, arr + n); 

	// initialising nested loops 
	for (int i = 0; i < n; i++) { 
		for (int j = i + 1; j < n; j++) { 

			// finding the sum of the numbers 
			if (search((arr[i] + arr[j]), j, n - 1, arr)) { 

				// printing out the first triplet 
				cout << "Numbers are: " << arr[i] << " "
					<< arr[j] << " " << (arr[i] + arr[j]); 
				return; 
			} 
		} 
	} 
	// if no such triplets are found 
	cout << "No such numbers exist" << endl; 
} 

int main() 
{ 
	int arr[] = { 5, 32, 1, 7, 10, 50, 19, 21, 2 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	findTriplet(arr, n); 
	return 0; 
}