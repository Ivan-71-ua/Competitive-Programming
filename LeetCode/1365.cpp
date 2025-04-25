#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
		std::vector<int> sorted = nums;
		std::sort(sorted.begin(), sorted.end());
		std::vector<int> ans(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			ans[i] = std::lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
		}
		return ans;
	}
};