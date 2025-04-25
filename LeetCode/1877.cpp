#include <bits/stdc++.h>


class Solution {
public:
	int minPairSum(std::vector<int>& nums) {
		int MAX = -1;
		std::stable_sort(nums.begin(), nums.end());
		for (int i = 0, j = nums.size() - 1; i < nums.size() / 2; i++, j--)
		{
			MAX = std::max(nums[i] + nums[j], MAX);
		}
		return MAX;
	}
};