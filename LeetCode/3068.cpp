#include <bits/stdc++.h>



class Solution {
public:
	long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) {
		int n = nums.size();
		std::vector<int> delta(n);
		long long sum = 0;
		for (auto num: nums)
		{
			sum += num;
		}
		
		for (int i = 0; i < n; i++)
		{
			delta[i] = (nums[i] ^ k) - nums[i];
		}
		std::stable_sort(delta.begin(), delta.end(), std::greater());
		for (int i = 1; i < n; i += 2)
		{
			if(delta[i]  + delta[i -1] < 0) break;
			sum += delta[i] + delta[i - 1];
		}
		return sum;
	}
};