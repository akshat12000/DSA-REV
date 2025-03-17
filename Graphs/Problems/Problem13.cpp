// C++ program to find the number of islands
// in a 2D matrix using BFS
#include <bits/stdc++.h>
using namespace std;

bool isDanger(int i, int j, int n, int m)
{
    return (i<0 || i>=n || j<0 || j>=m);
}

void numIslandsBfs(vector<vector<char>>& grid, int i, int j) {
    // Code here
    vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
    int n = grid.size();
    int m = grid[0].size();

    if(isDanger(i,j,n,m) || grid[i][j]=='0')
        return;
    
    queue<pair<int,int>> q;
    q.push({i,j});
    grid[i][j]='0';
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for(auto d:dir)
        {
            int tx = x+d[0];
            int ty = y+d[1];
            if(!isDanger(tx,ty,n,m) && grid[tx][ty]=='1')
            {
                grid[tx][ty]='0';
                q.push({tx,ty});
            }
        }
    }	
}

int numIslands(vector<vector<char>>& grid) {
        // Code here
	int n = grid.size();
    int m = grid[0].size();
    int islands = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1')
            {
                numIslandsBfs(grid,i,j);
                islands++;
            }
        }
    }
    return islands;
}

int main() {
    vector<vector<char>> grid = {
        { '1', '1', '0', '0', '0' },
        { '0', '1', '0', '0', '1' },
        { '1', '0', '0', '1', '1' },
        { '0', '0', '0', '0', '0' },
        { '1', '0', '1', '0', '1' }
    };
    cout << numIslands(grid) << endl;
    return 0;
}

// Time Complexity: O(N*M)
// Space Complexity: O(N*M)