#include <bits/stdc++.h>


class Solution {
public:
	int arrayPairSum(std::vector<int>& nums) {
		std::stable_sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0; i < nums.size(); i += 2)
		{
			res += nums[i];
		}
		return res;
	}
};