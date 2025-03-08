// C++ implementation of Flood Fill
// Algorithm using BFS
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(
    vector<vector<int>>& image, int sr, 
    int sc, int newColor) {

    // If the starting pixel already has the new color
    if (image[sr][sc] == newColor) {
        return image;
    }

    // Direction vectors for traversing 4 directions
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // Initialize the queue for BFS
    queue<pair<int, int>> q;
    int oldColor = image[sr][sc];
    q.push({sr, sc});
    
    // Change the color of the starting pixel
    image[sr][sc] = newColor;

    // Perform BFS
    while (!q.empty()) {
        pair<int, int> front = q.front();
        int x = front.first, y = front.second;
        q.pop();
        
        // Traverse all 4 directions
        for (const pair<int, int>& direction : directions) {
            int nx = x + direction.first;
            int ny = y + direction.second;
            
            // Check boundary conditions and color match
            if (nx >= 0 && nx < image.size() && 
                ny >= 0 && ny < image[0].size() && 
                image[nx][ny] == oldColor) {
                
                // Change the color and enqueue
                image[nx][ny] = newColor;
                q.push({nx, ny});
            }
        }
    }

    return image;
}

void printArray(vector<vector<int>>& image) {
    for (auto& row : image) {
        for (auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << "\n";
    }
}

int main() {
  
    vector<vector<int>> image = {
        {1, 1, 1}, 
        {1, 1, 0}, 
        {1, 0, 1}};
    
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = 
        floodFill(image, sr, sc, newColor);

    printArray(result);

    return 0;
}

// Time Complexity: O(N * M) where N is the number of rows and M is the number of columns in the image
// Space Complexity: O(N * M) where N is the number of rows and M is the number of columns in the image