#include <bits/stdc++.h>


class Solution {
	long long MOD = 1000000007LL;
public:
	int numberOfWays(int n, int x) {
		std::vector<std::vector< long long>> dp(n + 1, std::vector<long long>(n + 1));
		dp[0][0] = 1;
		for (int i = 1; i < n + 1; i++) {
			long long tmp = pow(i, x);
			//if(tmp > n) break;
			for (int j = 0; j < n + 1; j++) {
            dp[i][j] = dp[i -1][j];
				if(tmp <= j) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j - tmp]) % MOD;
				}
			}
		}
		return dp[n][n];
	}
};