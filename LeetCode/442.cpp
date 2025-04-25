#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> findDuplicates(std::vector<int>& nums) {
		std::vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[abs(nums[i]) - 1] > 0) {
				nums[abs(nums[i]) - 1] *= -1;
			} else {
				res.push_back(abs(nums[i]));
			}
		}
		return res;
	}
};