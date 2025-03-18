// A C++ Program to detect
// cycle in an undirected graph
#include <iostream>
#include <vector>
using namespace std;

// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool isCycleUtil(int v, vector<vector<int>>& adj, 
    vector<bool>& visited, int parent) {
                      
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    for (int i : adj[v]) {
        
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[i]) {
            if (isCycleUtil(i, adj, visited, v))
                return true;
        }
        
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (i != parent)
            return true;
    }
    
    return false;
}

// Returns true if the graph contains
// a cycle, else false.
bool isCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Call the recursive helper function
    // to detect cycle in different DFS trees
    for (int u = 0; u < V; u++) {
        
        // Don't recur for u if 
        // it is already visited
        if (!visited[u])
            if (isCycleUtil(u, adj, visited, -1))
                return true;
    }
    
    return false;
}

int main() {
    int V = 3;
    vector<vector<int>> adj(V);

    adj[1].push_back(0);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);

    if (isCycle(adj)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V), where V is the number of vertices in the graph.