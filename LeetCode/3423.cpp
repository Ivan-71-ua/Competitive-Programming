#include <bits/stdc++.h>


class Solution {
public:
	int maxAdjacentDistance(std::vector<int>& nums) {
		int res = abs(nums[0] - nums.back());
		for (int i = 1; i < nums.size(); i++) {
			res = std::max(res, abs(nums[i] - nums[i - 1]));
		}
		return res;
	}
};