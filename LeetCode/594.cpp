#include <bits/stdc++.h>



class Solution {
public:
	int findLHS(std::vector<int>& nums) {
		std::set<int> set(nums.begin(), nums.end());
		std::unordered_map<int, int> quat;
		for (int i = 0; i < nums.size(); i++)
		{
			quat[nums[i]]++;
		}
		int res = 0;
		int prev = *set.begin();
		for (auto now: set)
		{
			if(now - prev == 1)
				res = std::max(res, quat[now] + quat[prev]);
			prev = now;
		}
		return res;
	}
};