#include <bits/stdc++.h>





class Solution {
	const int MOD = 1000000007;

	int dfs(int idx, int k, std::string &target, std::vector<std::vector<long long>> &cnt, std::vector<std::vector<long long>> &dp) {
		if (idx == target.size()) return 1;
		if (k == cnt.size()) return 0;
		if (dp[idx][k] != -1) return dp[idx][k];

		int ch = target[idx] - 'a';
		dp[idx][k] = dfs(idx, k + 1, target, cnt, dp) % MOD;
		if (cnt[k][ch] > 0) {
			dp[idx][k] = (dp[idx][k] + cnt[k][ch] * dfs(idx + 1, k + 1, target, cnt, dp)) % MOD;
		}

		return dp[idx][k];
	}

public:
	int numWays(std::vector<std::string> &words, std::string target) {
		int m = words[0].size(), n = target.size();
		std::vector<std::vector<long long>> cnt(m, std::vector<long long>(26, 0));
		for (const auto &w : words) {
			for (int i = 0; i < w.size(); i++) {
				cnt[i][w[i] - 'a']++;
			}
		}
		std::vector<std::vector<long long>> dp(n, std::vector<long long>(m, -1));
		return dfs(0, 0, target, cnt, dp);
	}
};
