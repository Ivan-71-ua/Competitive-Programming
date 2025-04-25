#include <bits/stdc++.h>


class Solution {
public:
	long long minimumOperations(std::vector<int>& nums, std::vector<int>& target) {
		std::vector<int> diff(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			diff[i] = nums[i] - target[i];
		}
		
	}
};