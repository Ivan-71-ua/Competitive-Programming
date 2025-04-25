#include <bits/stdc++.h>


class Solution {
public:
	int partitionArray(std::vector<int>& nums, int k) {
		int maxs = *std::max_element(nums.begin(), nums.end());
		int mins = *std::min_element(nums.begin(), nums.end());
		int res = 0;
		std::vector<bool> num(maxs + 1);
		for (auto now: nums)
		{
			num[now] = true;
		}
		for (int i = mins; i <= maxs; i++)
		{
			if(num[i] && i - mins > k) {
				res++;
				mins = i;
			}
		}
		return res + 1;
	}
};