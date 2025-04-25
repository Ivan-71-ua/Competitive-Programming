#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier) {
		for (int i = 0; i < k; i++)
		{
			int max = 200;
			int max_id = -1;
			for (int j = 0; j < nums.size(); j++)
			{
				if(max < nums[j]) {
					max = nums[j];
					max_id = j;
				}
			}
			nums[max_id] = nums[max_id] * multiplier;
		}
		return nums;
	}
};