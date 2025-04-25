
#include <bits/stdc++.h>




class Solution {
public:
	std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
		std::vector<int> res = {};
		std::sort(nums.begin(), nums.end());
		int n = nums.size();
		std::vector<std::vector<int>> dp(n, std::vector<int>());
		for (int i = n - 1; i > -1; i++) {
			dp[i].push_back(nums[i]);
			for (int j = i + 1; j < n; j++) {
				if(nums[j] % nums[i] == 0) {
					int tmp_s = dp[j].size() + 1;
					if(tmp_s > dp[i].size()) {
						dp[i] = dp[j];
						dp[i].insert(dp[i].begin(), nums[i]);
					}
				}
			}
			if (dp[i].size() > res.size())
			{
				res = dp[i];
			}
		}
		return res;
	}
};