#include <bits/stdc++.h>



class Solution {
	const int MOD = 1e9 + 7;
public:
	int countOfPairs(std::vector<int>& nums) {
		int n = nums.size();
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(55, 0));

		for (int i = 0; i <= nums[0]; i++) {
			dp[0][i] = 1;
		}

		for (int idx = 1; idx < n; idx++) {
			for (int cur_v = 0; cur_v <= nums[idx]; cur_v++) {
				int way = 0;
				for (int prev_v = 0; prev_v <= 50; prev_v++) {
					if (cur_v >= prev_v && nums[idx] - cur_v <= nums[idx - 1] - prev_v) {
						way = (way + dp[idx - 1][prev_v]) % MOD;
					}
				}
				dp[idx][cur_v] = way;
			}
		}

		int total_way = 0;
		for (int cur = 0; cur <= 50; cur++) {
			total_way = (total_way + dp[n - 1][cur]) % MOD;
		}

		return total_way;
	}
};
