#include <bits/stdc++.h>



class Solution {
public:
	int minInsertions(std::string s) {
		int n = s.size();
		std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
		for (int i = n - 1; i > -1; i--)
		{
			for (int j = i; j < n; j++)
			{
				if(s[i] == s[j]) {
					if(j - i < 2) {
						dp[i][j] = j - i + 1;
					} else {
						dp[i][j] = 2 + dp[i + 1][j - 1];
					}
				} else {
					dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return n - dp[0][n - 1];
	}
};