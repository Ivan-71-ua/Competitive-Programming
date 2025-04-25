#include <bits/stdc++.h>


class Solution {
	const int MOD = 1e9 + 7;
	int get_all_arr(int idx, int cur_max, int cur_cost, int n, int m, int k, std::vector<std::vector<std::vector<int>>> &dp) {
		if(cur_cost > k)
			return 0;
		if(n == idx) {
			if(cur_cost == k)
				return 1;
			else
				return 0;
		}
		if(dp[idx][cur_max][cur_cost] != -1)
			return dp[idx][cur_max][cur_cost];
		int ans = 0;
		for (int num = 1; num <= m; num++)
		{
			if(num > cur_max)
				ans += get_all_arr(idx + 1, num, cur_cost + 1, n, m, k, dp);
			else
				ans += get_all_arr(idx + 1, cur_max, cur_cost, n, m, k, dp);
			ans = ans % MOD;
		}
		return dp[idx][cur_max][cur_cost] = ans;
	}
public:
	int numOfArrays(int n, int m, int k) {
		std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(k + 1, -1)));
		return get_all_arr(0, 0, 0, n, m, k, dp);
	}
};