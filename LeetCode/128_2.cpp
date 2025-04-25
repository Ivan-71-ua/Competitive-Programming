#include <bits/stdc++.h>

class Solution {
public:
	int longestConsecutive(std::vector<int>& nums) {
		std::set<int> val_num;
		for (int i = 0; i < nums.size(); i++)
		{
			val_num.insert(nums[i]);
		}
		int longest = 0;
		for (auto now: val_num)
		{
			if(!val_num.count(now -1)) {
				int leght = 0;
				while(val_num.count(now + leght))
					leght++;
				longest = std::max(longest, leght);
			}
		}
		return longest;
	}
};