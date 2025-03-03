// C++ program to Detect cycle in 
// an undirected graph using BFS
#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS from node start
bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            
            // If node is not visited,
            // push it into queue.
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } 
            
            // If node is visited and 
            // it is not the parent node.
            else if (neighbor != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        
        // If node is not visited,
        // start BFS from this node.
        if (!visited[i]) {
            
            // If cycle is found in this 
            // component.
            if (bfs(i, adj, visited)) {
                return true;
            }
        }
    }
    
    // If no cycle is found
    return false;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2, 3},
        {0, 2},
        {0, 1},
        {0, 4},
        {3}
    };

   isCycle(adj) ? cout<<"True": cout<<"False";

    return 0;
}

// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V) where V is the number of vertices in the graph.