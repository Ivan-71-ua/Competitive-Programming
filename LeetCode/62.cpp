#include <bits/stdc++.h>

class Solution {
public:
	int uniquePaths(int m, int n) {
		std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 1));
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};