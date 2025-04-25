#include <bits/stdc++.h>

class Solution {
public:
   int minimumDifference(std::vector<int>& nums, int k) {
		std::sort(nums.begin(), nums.end());
		int min = INT32_MAX;
		for (int i = 0; i <= nums.size() - k; i++)
		{
			if(nums[i +(k -1)] - nums[i] < min)
				min = nums[i + (k -1)] - nums[i];
		}
		return min;
	}
};
