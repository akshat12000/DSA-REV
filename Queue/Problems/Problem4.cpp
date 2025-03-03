// C++ program to implement BFS traversal of a graph
#include<bits/stdc++.h>
using namespace std;

// BFS from given source s
vector<int> bfsOfGraph(vector<vector<int>>& adj, int s)  {
    int V = adj.size();

    // create an array to store the traversal
    vector<int> res;

    // Create a queue for BFS
    queue<int> q;  
    
    // Initially mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Mark source node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // Iterate over the queue
    while (!q.empty()) {
      
        // Dequeue a vertex from queue and store it
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Get all adjacent vertices of the dequeued 
        // vertex curr If an adjacent has not been 
        // visited, mark it visited and enqueue it
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return res;
}

int main()  {

    vector<vector<int>> adj = { {2, 3, 1}, {0},
                                {0, 4}, {0}, {2}};
    int src = 0;
    vector<int> ans = bfsOfGraph(adj, src);
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)