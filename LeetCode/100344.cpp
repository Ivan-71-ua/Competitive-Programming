#include <bits/stdc++.h>




class Solution {
public:
	int minOperations(std::vector<int>& nums) {
		int op = 0;
		for (int i = 0; i < nums.size() - 2; i++)
		{
			if(nums[i] == 0) {
				nums[i] = 1;
				nums[i + 1] = 1 - nums[i + 1];
				nums[i + 2] = 1 - nums[i + 2];
				op++;
			}
		}
		int t = std::count(nums.begin(), nums.end(), 1);
		if(t == nums.size())
			return op;
		return -1;
	}
};