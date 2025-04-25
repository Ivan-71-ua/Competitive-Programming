#include <bits/stdc++.h>



class Solution {
public:
	int maximumBeauty(std::vector<int>& nums, int k) {
		std::sort(nums.begin(), nums.end());
		int res = 1;
		int l = 0;
		for (int r = 0; r < nums.size(); r++)
		{
			while(nums[r] - nums[l] > k * 2) {
				l++;
			}
			res = std::max(res, r - l + 1);
		}
		return res;
	}
};