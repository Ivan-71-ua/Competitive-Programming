#include <bits/stdc++.h>



class Solution {
public:
	int minimumOperations(std::vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			res += std::min(nums[i] % 3, 3 - nums[i] % 3);
		}
		return res;
	}
};