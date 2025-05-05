#include <bits/stdc++.h>


class Solution {
public:
	int numTilings(int n) {
		if(n == 1) return 1;
		if(n == 2) return 2;
		if(n == 3) return 5;
		std::vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 5;
		for (int i = 4; i <= n; i++) {
			dp[i] = (2 * (long)dp[i -1] + dp[i - 3]) % 1000000007;
		}
		return dp[n];
	}
};