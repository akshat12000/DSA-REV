// A C++ program to find bridges in a given undirected graph
#include<bits/stdc++.h>
using namespace std;

// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, 
                                  vector<int>& low, int parent);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    void bridge();    // prints all bridges
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

// A recursive function that finds and prints bridges using
// DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, 
                                  vector<int>& low, int parent)
{
    // A static variable is used for simplicity, we can 
    // avoid use of static variable by passing a pointer.
    static int time = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices adjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
          
          // 1. If v is parent 
          if(v==parent)
            continue;
      
          //2. If v is visited
          if(visited[v]){
          low[u]  = min(low[u], disc[v]);
        }
      
          //3. If v is not visited
          else{
          parent = u;
          bridgeUtil(v, visited, disc, low, parent);
  
          // update the low of u as it's quite possible 
          // a connection exists from v's descendants to u
          low[u]  = min(low[u], low[v]);
          
          // if the lowest possible time to reach vertex v
          // is greater than discovery time of u it means 
          // that v can be only be reached by vertex above v
          // so if that edge is removed v can't be reached so it's a bridge
          if (low[v] > disc[u])
              cout << u <<" " << v << endl;
          
        }
    }
}

// DFS based function to find all bridges. It uses recursive 
// function bridgeUtil()
void Graph::bridge()
{
    // Mark all the vertices as not visited disc and low as -1
    vector<bool> visited (V,false);
    vector<int> disc (V,-1);
      vector<int> low (V,-1);
    
      // Initially there is no parent so let it be -1
      int parent = -1;

    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}

// Driver program to test above function
int main()
{
    // Create graphs given in above diagrams
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.bridge();

    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.bridge();

    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.bridge();

    return 0;
}

// Time Complexity: O(V+E) where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V) where V is the number of vertices in the graph.