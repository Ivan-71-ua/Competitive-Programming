
#include <bits/stdc++.h>



class Solution {
	int cnt = 0;
	int cur_s = 0;
	void make_all(int idx, std::vector<int>& nums, int target) {
		if(idx >= nums.size()) {
			if(cur_s == target)
				cnt++;
			return;
		}
		cur_s += nums[idx];
		make_all(idx + 1, nums, target);
		cur_s -= nums[idx];

		cur_s -= nums[idx];
		make_all(idx + 1, nums, target);
		cur_s += nums[idx];
	}
public:
	int findTargetSumWays(std::vector<int>& nums, int target) {
		make_all(0, nums, target);
		return cnt;
	}
};