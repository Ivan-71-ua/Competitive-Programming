#include <bits/stdc++.h>



class Solution {
public:
	int partitionArray(std::vector<int>& nums, int k) {
		if(nums.size() == 1)
			return 1;
		int res = 0;
		std::stable_sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size();)
		{
			int j = i + 1;
			while(j < nums.size() && abs(nums[i] - nums[j]) <= k) {
				j++;
			}
			res++;
			i = j;
		}
		return res;
	}
};