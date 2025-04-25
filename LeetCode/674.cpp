#include <bits/stdc++.h>

class Solution {
public:
	int findLengthOfLCIS(std::vector<int>& nums) {
		nums.push_back(-1);
		int res = 0;
		int tmp = 0;
		for (int i = 0; i < nums.size() -1; i++)
		{
			if(nums[i] < nums[i +1])
				tmp++;
			else {
				res = std::max(tmp, res);
				tmp = 0;
			}
		}
		return res + 1;
	}
};