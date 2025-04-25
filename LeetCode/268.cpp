#include <bits/stdc++.h>

class Solution {
public:
	int missingNumber(std::vector<int>& nums) {
		int res = 0;
		for (int i = 1; i <= nums.size(); i++)
		{
			res = res ^ i;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			res ^= nums[i];
		}
		return res;
	}
};