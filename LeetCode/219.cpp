#include <bits/stdc++.h>


class Solution {
public:
	bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
		std::map<int, std::vector<int>> list;
		for (int i = 0; i < nums.size(); i++)
		{
			list[nums[i]].push_back(i);
		}
		if(list .size() == nums.size())
			return false;
		for (auto now : list)
		{
			if (now.second.size() > 1) {
				for (int i = 1; i < now.second.size(); i++)
				{
					if(abs(now.second[i - 1] - now.second[i]) <= k) {
						return true;
					}
				}
				
			}
		}
		return false;
	}
};