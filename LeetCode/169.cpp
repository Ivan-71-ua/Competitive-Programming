#include <bits/stdc++.h>

class Solution {
public:
   int majorityElement(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		return nums[nums.size() /2];
	}
};