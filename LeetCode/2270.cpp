#include <bits/stdc++.h>



class Solution {
public:
	int waysToSplitArray(std::vector<int>& nums) {
		long long sum = 0;
		long long cur_s = 0;
		for (auto &&v : nums)
		{
			sum += v;
		}
		int res = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			cur_s += nums[i];
			if(cur_s >= sum - cur_s) {
				res++;
			}
		}
		return res;
	}
};