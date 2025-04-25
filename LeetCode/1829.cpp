#include <bits/stdc++.h>



class Solution {
public:
	std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit) {
		int XOR = 0;
		std::vector<int> ans;
		for (auto now: nums)
		{
			XOR ^= now;
		}
		int max = 1 << maximumBit;
		for (int i = nums.size() -1; i > -1; i--)
		{
			ans.push_back((max - 1) ^ XOR);
			XOR ^= nums[i];
		}
		return ans;
	}
};