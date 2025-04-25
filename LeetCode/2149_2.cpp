#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> rearrangeArray(std::vector<int>& nums) {
		int i = 0, j = 1;
		std::vector<int> res(nums.size());
		for (auto now: nums)
		{
			if(now > 0) {
				res[i] = now;
				i += 2;
			} else {
				res[j] = now;
				j += 2;
			}
		}
		return res;
	}
};