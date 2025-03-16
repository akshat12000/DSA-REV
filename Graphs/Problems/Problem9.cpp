// C++ program to find the sum of dependencies 
#include <bits/stdc++.h> 
using namespace std; 

// To add an edge 
void addEdge(vector <int> adj[], int u,int v) 
{ 
	adj[u].push_back(v); 
} 

// find the sum of all dependencies 
int findSum(vector<int> adj[], int V) 
{ 
	int sum = 0; 

	// just find the size at each vector's index 
	for (int u = 0; u < V; u++) 
		sum += adj[u].size(); 

	return sum; 
} 

// Driver code 
int main() 
{ 
	int V = 4; 
	vector<int >adj[V]; 
	addEdge(adj, 0, 2); 
	addEdge(adj, 0, 3); 
	addEdge(adj, 1, 3); 
	addEdge(adj, 2, 3); 

	cout << "Sum of dependencies is "
		<< findSum(adj, V); 
	return 0; 
} 

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)