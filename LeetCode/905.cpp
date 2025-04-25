

#include <bits/stdc++.h>

class Solution {
public:
	std::vector<int> sortArrayByParity(std::vector<int>& nums) {
		std::vector<int> res;
		res.reserve(nums.size());
		for (auto now: nums)
		{
			if(now % 2 == 0)
				res.push_back(now);
		}
		for (auto now: nums)
		{
			if(now % 2 != 0)
				res.push_back(now);
		}
		return res;
	}
};