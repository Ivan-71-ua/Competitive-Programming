#include <bits/stdc++.h>

class Solution {
public:
   void moveZeroes(std::vector<int>& nums) {
		int n = nums.size();
		std::vector<int> used;
		for (int i = 0; i < n; i++)
		{
			if(nums[i] != 0)
				used.push_back(nums[i]);
		}
		for (int i = 0; i < used.size(); i++)
		{
			nums[i] = used[i];
		}
		if(n > used.size()) {
			for (int i = n - used.size(); i < n; i++)
			{
				nums[i] = 0;
			}
		}
	}
};