#include <bits/stdc++.h>

class Solution {
public:
	int longestSubarray(std::vector<int>& nums) {
		int maxs = 0, ans = 0, cur_l = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(maxs < nums[i]) {
				maxs = nums[i];
				cur_l = 0;
				ans = 0;
			}
			if(maxs == nums[i]) {
				cur_l++;
			} else {
				cur_l = 0;
			}
			ans = std::max(ans, cur_l);
		}
		return ans;
	}
};