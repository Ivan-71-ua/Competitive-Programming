#include <bits/stdc++.h>




class Solution {
public:
	bool check(std::vector<int>& nums) {
		int k = 0;
		for (int i = 1; i < nums.size(); i++) {
			if(nums[i -1] > nums[i])
				k++;
		}
		if(k > 1)
			return false;
		return nums[0] > nums.back();
	}
};