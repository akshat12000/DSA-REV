// C++ program to find the k smallest elements in the  
// array using max heap
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kSmallest(vector<int> &arr, int k) {
  
    // Max Priority Queue (Max-Heap)
    priority_queue<int> maxH;

    for (int i = 0; i < arr.size(); i++) {

        // Insert initial k elements in the max heap
        if (maxH.size() < k) 
            maxH.push(arr[i]);
      	
      	// If the top of heap is greater than the arr[i]
      	// then remove this and insert arr[i] 
      	else if(maxH.top() > arr[i]) {
         	maxH.pop();
          	maxH.push(arr[i]);
        }
    }

    
    vector<int> res;
  
  	// Max heap will contain only k 
  	// smallest element
    while (!maxH.empty()) {
        res.push_back(maxH.top());
        maxH.pop();
    }

   	return res;
}

int main() {
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
  
  	vector<int> res = kSmallest(arr, k);
  	for(int ele : res)
      	cout << ele << " ";
  	
  	return 0;
}

// Time Complexity: O(n*log(k))
// Space Complexity: O(k) as we are using a max heap of size k.