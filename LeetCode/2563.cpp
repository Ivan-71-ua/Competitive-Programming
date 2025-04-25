#include <bits/stdc++.h>



class Solution {
public:
	long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
		std::sort(nums.begin(), nums.end());
		long long res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int l = lower - nums[i];
			int u = upper - nums[i];
			auto lc = std::lower_bound(nums.begin(), nums.end(), l);
			auto uc = std::upper_bound(nums.begin(), nums.end(), u);
			if(lc == nums.end() ||  uc == nums.begin()) continue;
			int a = lc - nums.begin();
			int b = uc - nums.begin();
			res += b - a;
			if(a <= i && i <= b)
				res--;
		}
		return (res +1) /2;
	}
};