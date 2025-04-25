#include <bits/stdc++.h>


class Solution {
public:
	int mp[1000000];
	int res = 0;
	void backtrack(int start, int curr, std::vector<int>& nums)
	{
		for(int i = start; i < nums.size(); i++)
		{
			int temp = curr | nums[i];
			res = std::max(res, temp);
			mp[temp]++;
			backtrack(i + 1, temp, nums);
		}
	}
	int countMaxOrSubsets(std::vector<int>& nums) {
		memset(mp, 0, sizeof(mp));
		backtrack(0, 0, nums);
		return mp[res];
	}
};