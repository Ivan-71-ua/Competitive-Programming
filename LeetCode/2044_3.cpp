#include <bits/stdc++.h>

class Solution {
public:
	
	int countMaxOrSubsets(std::vector<int>& nums) {
		std::vector<int> dp(1 << 17, 0);
		int max_v = 0;
		dp[0] = 1;
		for(auto num: nums) {
			for (int i = max_v; i > -1; i--) {
				dp[i | num] += dp[i];
			}
			max_v |= num;
		}
		return dp[max_v];
	}
};