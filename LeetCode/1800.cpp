#include <bits/stdc++.h>




class Solution {
public:
	int maxAscendingSum(std::vector<int>& nums) {
		if( nums.size() == 1)
			return nums[0];
		int res = nums[0];
		int cur = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if(nums[i - 1] < nums[i]) {
				cur += nums[i];
			} else {
				res = std::max(cur, res);
				cur = nums[i];
			}
		}
		res = std::max(cur, res);
		return res;
	}
};