
#include <bits/stdc++.h>

class Solution {
public:
	int maximumProduct(std::vector<int>& nums) {
		std::stable_sort(nums.begin(), nums.end(), std::greater());
		if(nums[0] * nums[1] * nums[2] > *(nums.end() - 1) * *(nums.end() - 2) * nums[0])
			return nums[0] * nums[1] * nums[2];
		return *(nums.end() - 1) * *(nums.end() - 2) * nums[0];
	}
};