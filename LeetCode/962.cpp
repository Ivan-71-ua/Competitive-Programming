#include <bits/stdc++.h>




class Solution {
public:
	int maxWidthRamp(std::vector<int>& nums) {
		std::vector<int> monot(nums.size());
		int prev_m = 0;
		for (int i = nums.size() - 1; i > -1;i--) {
			monot[i] = std::max(nums[i], prev_m);
			prev_m = monot[i];
		}
		int res = 0;
		int l = 0;
		for (int r = 0; r < nums.size(); r++)
		{
			while(nums[l] > monot[r]) {
				l++;
			}
			res = std::max(res, r - l);
		}
		return res;
	}
};