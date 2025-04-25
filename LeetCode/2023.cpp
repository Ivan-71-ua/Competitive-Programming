#include <bits/stdc++.h>



class Solution {
public:
	int numOfPairs(std::vector<std::string>& nums, std::string target) {
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if(nums[i] + nums[j] == target) {
					res++;
				}
				if(nums[j] + nums[i] == target) {
					res++;
				}
			}
		}
		return res;
	}
};