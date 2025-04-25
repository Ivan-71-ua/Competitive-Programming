#include <bits/stdc++.h>


class Solution {
public:
	long long maxEnergyBoost(std::vector<int>& DrinkA, std::vector<int>& DrinkB) {
		int n = DrinkA.size();
		std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(2, 0));
		for (int i = 1; i <= n; i++)
		{
			dp[i][0] = std::max(dp[i][0], dp[i - 1][0] + DrinkA[i - 1]);
			dp[i][1] = std::max(dp[i][1], dp[i - 1][1] + DrinkB[i - 1]);
			dp[i][0] = std::max(dp[i][0], dp[i - 1][1]);
			dp[i][1] = std::max(dp[i][1], dp[i - 1][0]);
		}
		return std::max(dp[n][0], dp[n][1]);
	}
};