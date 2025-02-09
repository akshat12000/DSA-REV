#include<bits/stdc++.h>
using namespace std;

// Function to find all unique triplets that sum to zero
vector<vector<int>> threeSum(const vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    int n = arr.size();

    // Traverse each element as a potential first element
    for (int i = 0; i < n - 2; ++i)
    {
        // Skip duplicate elements
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int l = i + 1; // Left pointer
        int r = n - 1; // Right pointer

        while (l < r)
        {
            int sum = arr[i] + arr[l] + arr[r];

            if (sum == 0)
            { // Valid triplet found
                result.push_back({arr[i], arr[l], arr[r]});

                // Skip duplicate elements
                // for the second pointer
                while (l < r && arr[l] == arr[l + 1])
                    ++l;

                // Skip duplicate elements
                // for the third pointer
                while (l < r && arr[r] == arr[r - 1])
                    --r;

              	 // Move to the next potential pair
                ++l;
                --r;
            }
            // Need a larger sum
            else if (sum < 0) ++l;

            // Need a smaller sum
            else --r;
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(arr);

    for (const vector<int> &triplet : result)
    {
        for (int num : triplet)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}