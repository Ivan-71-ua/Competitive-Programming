#include <bits/stdc++.h>


class Solution {
	bool can_be(int a, int b, int c) {
		if(a + b > c && b +c > a && c + a > b)
			return true;
		return false;
	}
public:
	int largestPerimeter(std::vector<int>& nums) {
		int res = 0;
		std::stable_sort(nums.begin(), nums.end());
		for (int i = 2; i < nums.size(); i++)
		{
			if(can_be(nums[i -2], nums[i -1], nums[i])) {
				res = std::max(res, nums[i - 2] + nums[i - 1] + nums[i]);
			}
		}
		return res;
	}
};