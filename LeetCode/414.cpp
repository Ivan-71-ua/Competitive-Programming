#include <bits/stdc++.h>

class Solution {
public:
	int thirdMax(std::vector<int>& nums) {
		if(nums.size() < 3)
			return *std::max_element(begin(nums), end(nums));
		std::stable_sort(begin(nums), end(nums), std::greater());
		int flg = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if(nums[i -1] != nums[i])
				flg++;
			if(flg == 3)
				return nums[i];
		}
		if(flg < 3) {
			return *std::max_element(begin(nums), end(nums));
		}
		return 0;
	}
};