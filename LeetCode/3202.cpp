#include <bits/stdc++.h>

class Solution {
public:
	int maximumLength(std::vector<int>& nums, int k) {
		int res = 2, n = nums.size();
		std::vector<int> cnt(n, 0);
		for (int i = 0; i < n; i++) {
			cnt[i] = nums[i] % k;
		}
		for (int i = 0; i < k; i++) {
			std::vector<int> dp(k, 0);
			for (int j = 0; j < n; j++) {
				int mod = cnt[j], pos = (i - mod + k) % k;
				dp[mod] = dp[pos] + 1;
				res = std::max(res, dp[mod]);
			}
		}
		return res;
	}
};