
#include <bits/stdc++.h>


class Solution {
public:
	std::vector<long long> findPrefixScore(std::vector<int>& nums) {
		long long sum = 0;
		long long maxs = 0;
		std::vector<long long> ans(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			maxs = std::max(maxs, (long long)nums[i]);
			sum += maxs + nums[i];
			ans[i] = sum;
		}
		return ans;
	}
};


