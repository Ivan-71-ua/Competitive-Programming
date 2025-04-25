#include <bits/stdc++.h>


class Solution {
public:
   bool validPartition(std::vector<int>& nums) {
		std::vector<bool> dp(nums.size() + 1);
		dp[0] = true;
		for (int i = 2; i < nums.size() + 1; i++)
		{
			if(nums[i -2] == nums[i -1]) {
				if(dp[i -2] == 1)
					dp[i] = 1;
			} if(i > 2 && nums[i - 3] == nums[i -2] && nums[i -2] == nums[i -1]) {
				if(dp[i - 3] == 1)
					dp[i] = 1;
			} if(i > 2 && nums[i - 2] - nums[i -3] == 1 && nums[i - 1] - nums[i - 2] == 1) {
				if(dp[i - 3] == 1)
					dp[i] = 1;
			}
		}
		return dp[nums.size()];
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{10,10,10,10,10,10,10,10,10,10,10,10,1,1,1,5,5,5,8,8, 8,8,8,8,8,8,8,8};
	ans.validPartition(ss);
}