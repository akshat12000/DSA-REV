// C++ Program to find the number of islands using 
// Space Optimized BFS
#include <bits/stdc++.h>
using namespace std;

// A function to check if a given cell (r, c) 
// can be included in BFS
bool isSafe(vector<vector<char>>& M, int r, int c) {
    int rows = M.size();
    int cols = M[0].size();
    return (r >= 0) && (r < rows) && (c >= 0) && 
                     (c < cols) && (M[r][c] == '1');
}

// Breadth-First-Search to visit all cells in the 
// current island
void BFS(vector<vector<char>>& M, int sr, int sc) {
  
    // These arrays are used to get row and
    // column numbers of 8 neighbours of
    // a given cell
    vector<int> rNbr = { -1, -1, -1, 0, 0, 1, 1, 1 };
    vector<int> cNbr = { -1, 0, 1, -1, 1, -1, 0, 1 };

    // Simple BFS first step, we enqueue
    // source and mark it as visited
    queue<pair<int, int>> q;
    q.push({sr, sc});
      M[sr][sc] = '0';

    // Next step of BFS. We take out
    // items one by one from queue and
    // enqueue their unvisited adjacent
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // Go through all 8 adjacent
        for (int k = 0; k < 8; k++) {
            int newR = r + rNbr[k];
            int newC = c + cNbr[k];
            if (isSafe(M, newR, newC)) {
                M[newR][newC] = '0';
                q.push({newR, newC});
            }
        }
    }
}

// This function returns the number of islands 
// (connected components) in a graph
int countIslands(vector<vector<char>>& M) {
  
    // Mark all cells as not visited
    int rows = M.size();
    int cols = M[0].size();

    // Call BFS for every unvisited vertex
    // Whenever we see an unvisited vertex,
    // we increment res (number of islands) also.
    int res = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (M[r][c] == '1') {
                BFS(M, r, c);
                res++;
            }
        }
    }

    return res;
}

int main() {
    vector<vector<char>> M = { { '1', '1', '0', '0', '0' },
                              { '0', '1', '0', '0', '1' },
                              { '1', '0', '0', '1', '1' },
                              { '0', '0', '0', '0', '0' },
                              { '1', '0', '1', '1', '0' } };

    cout << countIslands(M);
    return 0;
}

// Time Complexity: O(ROW x COL)
// Space Complexity: O(ROW + COL) for the queue