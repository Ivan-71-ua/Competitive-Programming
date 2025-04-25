#include <bits/stdc++.h>


class Solution {
public:
   int lengthOfLIS(std::vector<int>& nums) {
		std::vector<int> dp(nums.size(), 1);
		for (int i = 1; i < nums.size(); i++)
		{
			int j = i - 1;
			while(j >= 0) {
				if(nums[j] < nums[i]) {
					dp[i] = std::max(dp[i], 1 + dp[j]);
				}
				j--;
			}
		}
		return *std::max_element(dp.begin(), dp.end());
	}
};

int main() {
	Solution ans;
	std::vector<int> ss{1, 3, 6, 7, 9, 4, 10, 5, 6};
	ans.lengthOfLIS(ss);
}