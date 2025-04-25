#include <bits/stdc++.h>


class Solution {
public:
   int singleNumber(std::vector<int>& nums) {
		std::map<int, int> tp;
		for (int i = 0; i < nums.size(); i++)
		{
			tp[nums[i]]++;
		}
		for (auto now: tp)
		{
			if(now.second == 1)
				return now.first;
		}
		return 0;
	}
};