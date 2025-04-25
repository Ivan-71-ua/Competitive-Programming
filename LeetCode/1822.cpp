#include <bits/stdc++.h>

class Solution {
public:
   int arraySign(std::vector<int>& nums) {
		uint16_t negative = 0;
		for (uint16_t i = 0; i < nums.size(); i++)
		{
			if(nums[i] == 0)
				return 0;
			if(nums[i] < 0)
				negative++;
		}
		if( negative % 2 == 0)
			return 1;
		return -1;
	}
};