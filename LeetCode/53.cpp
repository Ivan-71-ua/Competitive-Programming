
#include <bits/stdc++.h>



class Solution {
public:
	int maxSubArray(std::vector<int>& nums) {
		int max_sum = nums[0];
		int cur_sum = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if(cur_sum < 0)
				cur_sum = 0;
			cur_sum += nums[i];
			max_sum = std::max(max_sum, cur_sum);
			
		}
		return max_sum;
	}
};