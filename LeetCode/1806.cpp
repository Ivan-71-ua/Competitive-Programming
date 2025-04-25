#include <bits/stdc++.h>

class Solution {
	bool is(std::vector<int> &nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != i)
				return false;
		}
		return true;
	}
public:
	int reinitializePermutation(int n) {
		std::vector<int> nums(n);
		for (int i = 0; i < n; i++)
		{
			nums[i] = i;
		}
		int k = 0;
		do {
			k++;
			std::vector<int> tmp(n);
			for (int i = 0; i < n; i++)
			{
				if(i & 1) {
					tmp[i] = nums[n / 2 + (i - 1) / 2];
				} else {
					tmp[i] = nums[i / 2];
				}
			}
			nums = tmp;
		} while (!is(nums));
		return k;
	}
};