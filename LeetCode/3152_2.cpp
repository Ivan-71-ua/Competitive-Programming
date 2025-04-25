#include <bits/stdc++.h>



class Solution {
public:
	std::vector<bool> isArraySpecial(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
		std::vector<int> pref(nums.size(), 1);
		for (int i = 1; i < nums.size(); i++)
		{
			if((nums[i] + nums[i -1]) & 1) {
				pref[i] += pref[i - 1];
			} 
		}
		std::vector<bool> ans(queries.size());
		for (int i = 0; i < queries.size(); i++)
		{
			int s = queries[i][0], f = queries[i][1];
			if(pref[f] >= (f - s +1)) {
				ans[i] = true;
			}
		}
		return ans;
	}
};