#include <bits/stdc++.h>
using namespace std;

bool check4Sum(vector<int>& arr, int target) {
    vector<vector<int>> res;
    int n = arr.size();

    // Sort the array in increasing order so that
    // we can later apply two pointer tecnique
    sort(arr.begin(), arr.end());

    // Fix the first two elements one by one
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {

            // Find the remaining two elements
            // using two pointers
            int l = j + 1;
            int r = n - 1;
            while (l < r) {
                int sum = arr[i] + arr[j] + arr[l] + arr[r];

                if (sum == target) {
                    return true;
                    l++;
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<int> arr = {1, 1, 1, 1, 1};
    int target = 4;
    cout << (check4Sum(arr, target)? "True" : "False");
    return 0;
}