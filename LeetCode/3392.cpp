

#include <bits/stdc++.h>


class Solution {
public:
	int countSubarrays(std::vector<int>& nums) {
		int n = nums.size(), res = 0;
		for (int i = 1; i < n; i++) {
			if(nums[i- 1] + nums[i + 1] == nums[i] / 2.0) {
				res++;
			} 
		}
		return res;
	}
};