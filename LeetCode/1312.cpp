#include <bits/stdc++.h>



class Solution {
public:
	int minInsertions(std::string s) {
		int n = s.size();
		std::vector<std::vector<int>> dp(n, std::vector<int>(n, n + 1));
		for (int i = n - 1; i > -1; i--)
		{
			for (int j = i; j < n; j++)
			{
				if(s[i] == s[j]) {
					if(j - i < 2) {
						dp[i][j] = 0;
					} else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				} else {
					dp[i][j] = 1 + std::min(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
};