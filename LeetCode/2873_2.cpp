
#include <bits/stdc++.h>


class Solution {
public:
	long long maximumTripletValue(std::vector<int>& nums) {
		if(nums.size() < 3) {
			return 0;
		}
		long long res = 0, n = nums.size();
		long long fist = nums[0], dobut = LLONG_MIN;
		for (int i = 1; i < n - 1; i++) {
			dobut = std::max(dobut, fist - nums[i]);
			fist = std::max(fist, (long long)nums[i]);
			res = std::max(res, dobut * nums[i + 1]);
		}
		return res;
	}
};



