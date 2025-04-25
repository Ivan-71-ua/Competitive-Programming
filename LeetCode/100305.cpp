#include <bits/stdc++.h>


class Solution {
	const int MOD = 1000000007;
public:
	int valueAfterKSeconds(int n, int k) {
		std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n, 1));
		//for (int i = 0; i < n; ++i) {
			//dp[0][i] = 1;
		//}
		for (int t = 1; t <= k; ++t) {
			dp[t][0] = dp[t-1][0];
			for (int i = 1; i < n; ++i) {
				dp[t][i] = (dp[t][i-1] + dp[t-1][i]) % MOD;
			}
		}
		return dp[k][n-1];
	}
};