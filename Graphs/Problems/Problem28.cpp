// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(vector<vector<int>> &graph) {
    int V = graph.size();

    // Add all vertices one by one to
    // the set of intermediate vertices.
    for (int k = 0; k < V; k++) {

        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {

            // Pick all vertices as destination
            // for the above picked source
            for (int j = 0; j < V; j++) {

                // If vertex k is on the shortest path from
                // i to j, then update the value of graph[i][j]

                if ((graph[i][j] == -1 || 
                    graph[i][j] > (graph[i][k] + graph[k][j]))
                    && (graph[k][j] != -1 && graph[i][k] != -1))
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main() {

    vector<vector<int>> graph = {
        {0, 4, -1, 5, -1},
        {-1, 0, 1, -1, 6},
        {2, -1, 0, 3, -1},
        {-1, -1, 1, 0, 2},
        {1, -1, -1, 4, 0}
    };

    floydWarshall(graph);
    for(int i = 0; i<graph.size(); i++) {
        for(int j = 0; j<graph.size(); j++) {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Time Complexity: O(V^3)
// Space Complexity: O(V^2)