// To find the minimum number of dice throws required to reach the destination or last cell from the source or 1st cell.
#include <bits/stdc++.h>
using namespace std;

int minThrow(int N, int arr[]){
    // code here
    map<int,int> ladder;
    map<int,int> snake;
    
    for (int i=0;i<2*N;i=i+2){
        if (arr[i]<arr[i+1]){
            ladder[arr[i]]=arr[i+1];
        }
        else {
            snake[arr[i]]=arr[i+1];
        }
    }
    queue<pair<int,int>> q;
    q.push({0,1});
    while (!q.empty()){
        int loc=q.front().second;
        int step=q.front().first;
        q.pop();
        if (loc==30) return step;
        if (loc>30) continue;
        for (int k=1;k<=6;k++){
            int newloc=loc+k;
            if (ladder.find(newloc)!=ladder.end()){
                q.push({step+1,ladder[newloc]});
            }
            else if (snake.find(newloc)!=snake.end()){
                q.push({step+1,snake[newloc]});
            }
            else {
                q.push({step+1,newloc});
            }
        }
    } 
}

int main(){
    int N = 8;
    int arr[] = {3, 22, 5, 8, 11, 26, 20, 29, 17, 4, 19, 7, 27, 1, 21, 9};
    cout << minThrow(N, arr) << endl;
    return 0;
}

// Time Complexity: O(N) where N is the number of cells in the board.
// Space Complexity: O(N) where N is the number of cells in the board.