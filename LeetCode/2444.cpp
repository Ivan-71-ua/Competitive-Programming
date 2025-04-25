#include <bits/stdc++.h>


class Solution {
public:
	long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
		long long ans = 0;
		int min_i = -1, max_i = -1, bad_i = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] < minK || nums[i] > maxK) {
				bad_i = i;
			} 
			if(nums[i] == minK)
				min_i = i;
			if(nums[i] == maxK)
				max_i = i;
			ans += std::max(0, std::min(min_i, max_i) - bad_i);
		}
		return ans;
	}
};