// C++ implementation of largest triplet
// multiplication
#include <bits/stdc++.h>
using namespace std;

vector<int> largestTripletProducts(vector<int>& arr) {
    priority_queue<int> pq;
    vector<int> result;
    
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);

        // If there are less than 3 elements, push -1
        if (pq.size() < 3) {
            result.push_back(-1);
        } else {
            // Extract top 3 elements
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            int third = pq.top(); pq.pop();

            result.push_back(first * second * third);

            // Push them back
            pq.push(first);
            pq.push(second);
            pq.push(third);
        }
    }
    return result;
}

void printArr(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Driver Code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> result = largestTripletProducts(arr);
    printArr(result);
    return 0;
}

// Time complexity: O(N log N) for each element
// Space complexity: O(N) for priority queue