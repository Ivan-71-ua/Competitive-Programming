#include <bits/stdc++.h>



class Solution {
	bool can_div(int by, std::vector<int>& nums, int maxOperations) {
		int ops = 0;
		for (auto &k : nums)
		{
			ops += ((k + by - 1) / by) - 1;
			if(ops > maxOperations)
				return false;
		}
		return true;
	}
public:
	int minimumSize(std::vector<int>& nums, int maxOperations) {
		int l = 0;
		int r = *std::max_element(nums.begin(), nums.end());
		while(l < r) {
			int m = l + (r - l) / 2;
			if(can_div(m, nums, maxOperations)) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return l;
	}
};