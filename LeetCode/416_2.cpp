
#include <bits/stdc++.h>


class Solution {
public:
	bool canPartition(std::vector<int>& nums) {
		long long sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		if(sum & 1) return false;
		sum /= 2;
		std::vector<bool> dp(sum + 1, false);
		dp[0] = true;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = sum; j >= nums[i]; j--) {
				dp[j] = dp[j] || dp[j - nums[i]];
				if(dp[sum]) {
					return true;
				}
			}
		}
		return dp[sum];
	}
};