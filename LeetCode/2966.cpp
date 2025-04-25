#include <bits/stdc++.h>


class Solution {
public:
	std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
		std::stable_sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> res;
		for (int i = 0; i < nums.size(); i+= 3)
		{
			if(nums[i + 2] - nums[i] > k)
				return {};
			res.push_back({nums[i], nums[i + 1], nums[i + 2]});
		}
		return res;
	}
};