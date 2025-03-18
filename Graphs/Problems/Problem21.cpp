// To detect negative weight cycle in a graph
#include<bits/stdc++.h>
using namespace std;

int isNegativeWeightCycleHelper(int n, vector<vector<int>>&edges, int src)
{
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<edges.size(); j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if(dist[u] != INT_MAX && dist[u]+w<dist[v]){
            return 1;
        }
    }
    return 0;
}

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    
    for(int i=0;i<edges.size();i++)
    {
        if(isNegativeWeightCycleHelper(n,edges,edges[i][0])){
            return 1;
        }
    }

    return 0;
}

int main(){
    int n = 3;
    vector<vector<int>>edges = {{0,1,-1},{1,2,-2},{2,0,-3}};
    cout<<isNegativeWeightCycle(n,edges);
	return 0;
}
