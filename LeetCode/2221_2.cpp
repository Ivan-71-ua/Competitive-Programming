#include <bits/stdc++.h>




class Solution {
public:
	int triangularSum(std::vector<int>& nums) {
		int n = nums.size();
		while(n != 1) {
			std::vector<int> tmp;
			for (int i = 0; i < n - 1; i++)
			{
				nums[i] = (nums[i] + nums[i + 1]) % 10;
			}
			n--;
		}
		return nums[0];
	}
};