#include <bits/stdc++.h>

class Solution {
public:
	int longestSubarray(std::vector<int>& nums) {
		int maxs = *std::max_element(nums.begin(), nums.end());
		int ans = 0;
		int prev = -1, cur_max = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == maxs) {
				if(prev == maxs) {
					cur_max++;
				} else {
					cur_max = 1;
				}
				ans = std::max(cur_max, ans);
			}
			prev = nums[i];
		}
		return ans;
	}
};