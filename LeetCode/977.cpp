#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> sortedSquares(std::vector<int>& nums) {
		int i = 0;
		while(nums[i] < 0 && i + 1 < nums.size())
			i++;
		std::vector<int> ans(nums.size());
		int cur_p = 0;
		int l = i - 1, r = i;
		while(l > -1 && r < nums.size()) {
			if(abs(nums[l]) < abs(nums[r])) {
				ans[cur_p++] = nums[l] * nums[l];
				l--;
			} else {
				ans[cur_p++] = nums[r] * nums[r];
				r++;
			}
		}
		while(l > -1) {
			ans[cur_p++] = nums[l] * nums[l];
			l--;
		}
		while(r < nums.size()) {
			ans[cur_p++] = nums[r] * nums[r];
			r++;
		}
		return ans;
	}
};