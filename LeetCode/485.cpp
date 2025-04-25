#include <bits/stdc++.h>

class Solution {
public:
	int findMaxConsecutiveOnes(std::vector<int>& nums) {
		int res = 0;
		int cur = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == 1) {
				cur++;
				res = std::max(res, cur);
			} else {
				cur = 0;
			}
		}
		return res;
	}
};