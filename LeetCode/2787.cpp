
#include <bits/stdc++.h>

class Solution {
	long long MOD = 1000000007LL;
public:
	int numberOfWays(int n, int x) {
		std::vector<long long> dp(n + 1, 0);
		std::vector<int> unic_el;
		for (int i = 1; ; i++) {
			int tmp = pow(i, x);
			if(tmp > n) break;
			unic_el.push_back(tmp);
		}
		dp[0] = 1;
		for (int i = 0; i < unic_el.size(); i++) {
			for (int j = n; j >= unic_el[i]; j--) {
				dp[j] = (dp[j] + dp[j - unic_el[i]]) % MOD;
			}
		}
		return dp[n];
	}
};