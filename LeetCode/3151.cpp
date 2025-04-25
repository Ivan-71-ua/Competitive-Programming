#include <bits/stdc++.h>




class Solution {
public:
	bool isArraySpecial(std::vector<int>& nums) {
		if(nums.size() < 2)
			return true;
		for (int i = 1; i < nums.size(); i++) {
			if(!((nums[i] + nums[i-1]) & 1))
				return false;
		}
		return true;
	}
};