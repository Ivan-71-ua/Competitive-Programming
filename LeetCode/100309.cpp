#include <bits/stdc++.h>


class Solution {
public:
	int duplicateNumbersXOR(std::vector<int>& nums) {
		std::unordered_map<int, int> quant;
		for (int i = 0; i < nums.size(); i++)
		{
			quant[nums[i]]++;
		}
		int res = 0;
		for (auto &&now : quant)
		{
			if(now.second > 1) {
				res ^= now.first;
			}
		}
		return res;
	}
};