#include <bits/stdc++.h>




class Solution {
	int dp[2001][4001];
	int Find_Biggest_Less(int pos, int sum, std::vector<int> &nums) {
		if(pos == nums.size())
			return 0;
		int ans = -1;
		if(dp[pos][sum] == -1) {
			return dp[pos][sum];
		}
		if(nums[pos] > sum) {
			ans = std::max(ans, nums[pos] + Find_Biggest_Less(pos + 1, sum + nums[pos], nums));
			ans = std::max(ans, Find_Biggest_Less(pos + 1, sum, nums));
		} else {
			ans = std::max(ans, Find_Biggest_Less(pos + 1, sum, nums));
		}
		return dp[pos][sum] = ans;
	}
public:
	int maxTotalReward(std::vector<int>& rewardValues) {
		std::set<int> tmp(rewardValues.begin(), rewardValues.end());
		std::vector<int> nums(tmp.begin(), tmp.end());
		memset(dp, -1, sizeof(dp));
		return Find_Biggest_Less(0, 0, nums);
		
	}
};


int main() {
	Solution ans;
	std::vector<int> aa{1, 6, 4, 3, 2};
	ans.maxTotalReward(aa);
}