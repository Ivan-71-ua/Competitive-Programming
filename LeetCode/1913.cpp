#include <bits/stdc++.h>


class Solution {
public:
   int maxProductDifference(std::vector<int>& nums) {
		int max = -1, max2 = -2, min = 10001, min2 = 1002;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] >= max) {
				max2 = max;
				max = nums[i];
			}
			else if(nums[i] >= max2 ) {
				max2 = nums[i];
			}
			if(min >= nums[i]) {
				min2 = min;
				min = nums[i];
			}
			else if(min2 >= nums[i]) {
				min2 = nums[i];
			}
		}
		return (max * max2) - (min * min2);
	}
};