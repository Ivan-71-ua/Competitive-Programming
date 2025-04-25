#include <bits/stdc++.h>



class Solution {
public:
	int numOfPairs(std::vector<std::string>& nums, std::string target) {
		int res = 0;
		std::map<std::string, int> used;
		for (auto now: nums)
		{
			used[now]++;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			int l = nums[i].size();
			if(target.substr(0,l) == nums[i]) {
				res += used[target.substr(l)];
				if(target.substr(0, l)== target.substr(l))
					res--;
			}
		}
		return res;
	}
};