// C++ program to find Kth largest element in a stream
// Using Heaps
#include <bits/stdc++.h>
using namespace std;

vector<int> kthLargest(int k, int arr[], int n)
{
	vector<int> ans(n);

	// Creating a min-heap using priority queue
	priority_queue<int, vector<int>, greater<int> > pq;

	// Iterating through each element
	for (int i = 0; i < n; i++) {
		// If size of priority
		// queue is less than k
		if (pq.size() < k)
			pq.push(arr[i]);
		else {
			if (arr[i] > pq.top()) {
				pq.pop();
				pq.push(arr[i]);
			}
		}

		// If size is less than k
		if (pq.size() < k)
			ans[i] = -1;
		else
			ans[i] = pq.top();
	}

	return ans;
}

// Driver Code
int main()
{
	int n = 6;
	int arr[n] = { 1, 2, 3, 4, 5, 6 };
	int k = 4;

	// Function call
	vector<int> v = kthLargest(k, arr, n);
	for (auto it : v)
		cout << it << " ";
	return 0;
}

// Time complexity: O(N log K) for each element
// Space complexity: O(K) for priority queue