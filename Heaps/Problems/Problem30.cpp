// Efficient C++ program to find smallest
// derangement.
#include <bits/stdc++.h>

void generate_derangement(int N)
{	 
	// Generate Sequence S
	int S[N + 1];
	for (int i = 1; i <= N; i++)
		S[i] = i;

	// Generate Derangement
	int D[N + 1];
	for (int i = 1; i <= N; i += 2) {
		if (i == N && i%N!=0) {

			// Only if i is odd
			// Swap D[N-1] and D[N]
			int temp=D[N];
			D[N] = D[N - 1];
			D[N - 1] = temp;
		}
		else {
			D[i] = i + 1;
			D[i + 1] = i;
		}
	}

	// Print Derangement
	for (int i = 1; i <= N; i++) 
		printf("%d ", D[i]); 
	printf("\n");
}

// Driver Program
int main()
{
	generate_derangement(10);
	return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)