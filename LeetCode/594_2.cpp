#include <bits/stdc++.h>



class Solution {
public:
	int findLHS(std::vector<int>& nums) {
		std::unordered_map<int, int> quat;
		for (int i = 0; i < nums.size(); i++)
		{
			quat[nums[i]]++;
		}
		int res = 0;
		for (auto now: quat)
		{
			if(quat.count(now.first +1))
				res = std::max(res, now.second + quat[now.first +1]);
		}
		return res;
	}
};