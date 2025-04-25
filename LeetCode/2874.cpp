
#include <bits/stdc++.h>



class Solution {
public:
	long long maximumTripletValue(std::vector<int>& nums) {
		long long res = 0, first = nums[0], diff = LLONG_MIN;
		for (int i = 1; i < nums.size() - 1; i++) {
			diff = std::max(diff, first - nums[i]);
			first = std::max(first, (long long)nums[i]);
			res = std::max(res, diff * nums[i + 1]);
		}
		return res;
	}
};