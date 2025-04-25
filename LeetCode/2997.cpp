#include <bits/stdc++.h>


class Solution {
public:
	int minOperations(std::vector<int>& nums, int k) {
		int XOR = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			XOR ^= nums[i];
		}
		int res = k ^ XOR;
		std::bitset<32> dif(res);
		return dif.count();
	}
};