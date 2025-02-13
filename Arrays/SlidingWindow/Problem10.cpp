// Largest sum subarray with at-least k numbers
#include<bits/stdc++.h>

long long int maxSumWithK(long long int a[],
						long long int n, long long int k)
{
	long long int sum = 0;
	for (long long int i = 0; i < k; i++) {
		sum += a[i];
	}

	long long int last = 0;
	long long int j = 0;
	long long int ans = LLONG_MIN;
	ans = (ans > sum) ? ans : sum;
	for (long long int i = k; i < n; i++) {
		sum = sum + a[i];
		last = last + a[j++];
		ans = (ans > sum) ? ans : sum;
		if (last < 0) {
			sum = sum - last;
			ans = (ans > sum) ? ans : sum;
			last = 0;
		}
	}
	return ans;
}

int main()
{
	long long int a[] = { 1, 2, 3, -10, -3 };
	long long int k = 4;
	long long int n = sizeof(a) / sizeof(a[0]);
	printf("%lld", maxSumWithK(a, n, k));
	return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)