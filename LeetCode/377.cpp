#include <bits/stdc++.h>


class Solution {
public:
   long long combinationSum4(std::vector<int>& nums, int target) {
		std::vector<unsigned int> dp(target + 1, 0);
		dp[0] = 1;
		for (long long i = 1; i < target + 1; i++)
		{
			for (long long j = 0; j < nums.size(); j++)
			{
				if(i - nums[j] > -1) {
					unsigned int tp = std::max(dp[i], dp[i - nums[j]]);
					if(tp > 0) {
						if(i - nums[j] == 0) dp[i]++;
						else {
							dp[i] += dp[i - nums[j]];
						}
					}
				}
			}
		}
		return dp[target];
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{1, 2, 3};
	ans.combinationSum4(ss, 4);
}