#include <bits/stdc++.h>



class Solution {
public:
	std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {
		std::vector<bool> ans(nums.size());
		int k = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == 1) {
				k = k * 2 + 1;
			} else {
				k *= 2;
			}
			if(k % 5 == 0)
				ans[i] = true;
			else
				ans[i] = false;
			k %= 5;
		}
		return ans;
	}
};