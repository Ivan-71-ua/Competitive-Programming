
#include <bits/stdc++.h>

class Solution {
public:
	int dominantIndex(std::vector<int>& nums) {
		int maxl = *std::max_element(nums.begin(), nums.end());
		int maxl_in = std::max_element(nums.begin(), nums.end()) - nums.begin();
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != maxl && nums[i] * 2 > maxl) {
				return -1;
			}
		}
		return maxl_in;
	}
};