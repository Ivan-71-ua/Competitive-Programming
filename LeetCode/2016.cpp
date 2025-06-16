#include <bits/stdc++.h>




class Solution {
public:
	int maximumDifference(std::vector<int>& nums) {
		int n  = nums.size(), maxr = nums[n - 1], res = -1;
		for (int i = n - 2; i > -1; i--) {
			if(nums[i] < maxr) {
				res = std::max(res, maxr - nums[i]);
			} else {
				maxr = nums[i];
			}
		}
		return res;
	}
};