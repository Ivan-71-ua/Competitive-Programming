#include <bits/stdc++.h>


class Solution {
public:
	int countDistinctIntegers(std::vector<int>& nums) {
		std::bitset<1000001> intiger;
		for (int i = 0; i < nums.size(); i++)
		{
			intiger.set(nums[i]);
			int res = 0;
			while(nums[i]) {
				res *= 10;
				res += nums[i] % 10;
				nums[i] /= 10;
			}
			intiger.set(res);
		}
		return intiger.count();
	}
};