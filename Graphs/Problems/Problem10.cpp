// To find the cell with maximum weight in a given matrix
#include <bits/stdc++.h>
using namespace std;

// Function to find Max Weight Cell
int maxWeightCell(int N, vector<int> Edge)
{

	// Initializing temp with 0
	vector<int> temp(N, 0);

	// Traversing the Edge array
	for (int i = 0; i < N; i++) {

		// Checking if the value is not
		// equal to -1
		if (Edge[i] != -1) {

			// Adding weight to the
			// destination cell
			temp[Edge[i]] += i;
		}
	}

	// Getting the index with
	// maximum value
	int ans = max_element(temp.begin(), temp.end())
			- temp.begin();
	return ans;
}

// Drivers code
int main()
{

	// Size of Edge
	int N = 4;

	vector<int> Edge{ 2, 0, -1, 2 };

	// Printing value
	cout << maxWeightCell(N, Edge) << endl;
	return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(N)