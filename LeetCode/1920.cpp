#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> buildArray(std::vector<int>& nums) {
		int n = nums.size();
		std::vector<int> ans(n);
		for (int i = 0; i < n; i++)
		{
			ans[i] = nums[nums[i]];
		}
		return ans;
	}
};