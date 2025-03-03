//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& adj) {
    unordered_map<int,int>mp;
    queue<pair<int,int>>q;
    q.push({0,0});
    mp[0]=0;
    while(!q.empty())
    {
        auto x = q.front();
        q.pop();
        for(auto z:adj[x.first]){
            if(mp.find(z)==mp.end()){
                mp[z] = (x.second == 0)?1:0;
                q.push({z,mp[z]});
            }else{
                int col = mp[z];
                if(col == x.second)
                    return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout<<isBipartite(adj);
    return 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)