#include <bits/stdc++.h>


class Solution {
	const int MOD = 1000000000 + 7;
public:
	int valueAfterKSeconds(int n, int k) {
		std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n, 1));
		for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
			}
		}
		return dp[k][n - 1];
	}
};