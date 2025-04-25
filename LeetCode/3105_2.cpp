#include <bits/stdc++.h>



class Solution {
public:
	int longestMonotonicSubarray(std::vector<int>& nums) {
		int res = 1, inc = 1, dec = 1;
		if(nums.size() == 1)
			return 1;
		for (int i = 1; i < nums.size(); i++) {
			if(nums[i] > nums[i -1]) {
				inc++;
				dec = 1;
			} else if(nums[i] < nums[i - 1]) {
				dec++;
				inc = 1;
			} else {
				inc = dec = 1;
			}
			res = std::max({res, inc, dec});
		}
		return res;
	}
};