// C++ program for find k closest point to 
// origin using max heap.
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Function to calculate squared 
// distance from the origin
int squaredDis(vector<int>& point) {
    return point[0] * point[0] + 
      point[1] * point[1];
}

// Function to find k closest points to
// the origin
vector<vector<int>> kClosest(
  vector<vector<int>>& points, int k) {
    
    // Max heap to store points with their 
    // squared distances
    priority_queue<pair<int, vector<int>>> maxHeap;

    // Iterate through each point
    for (int i=0;i<points.size();i++) {
        int dist = squaredDis(points[i]);

        if (maxHeap.size() < k) {
            
            // If the heap size is less than k, 
            // insert the point
            maxHeap.push({dist, points[i]});
        } else {
            
            // If the heap size is k, compare with
            // the top element
            if (dist < maxHeap.top().first) {
                
                // Replace the top element if the
                // current point is closer
                maxHeap.pop();
                maxHeap.push({dist, points[i]});
            }
            // Else, ignore the current point
        }
    }

    // Take the k closest points from the heap
    vector<vector<int>> res;
    while (!maxHeap.empty()) {
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return res;
}

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, 
                                    {5, -1}, {3, 2}, {1, 1}};
    int k = 3;
    
    vector<vector<int>> res = kClosest(points, k);
    
    for (vector<int>point : res) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }

    return 0;
}

// Time Complexity: O(NlogK)
// Space Complexity: O(K)