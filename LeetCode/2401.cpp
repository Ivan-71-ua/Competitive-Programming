#include <bits/stdc++.h>




class Solution {
public:
	int longestNiceSubarray(std::vector<int>& nums) {
		int n = nums.size();
		int res = 1;
		int acum = 0;
		int j = 0;
		for (int i = 0; i < n; i++) {
			while(nums[i] & acum) {
				acum ^= nums[j++];
			}
			acum ^= nums[i];
			res = std::max(res, i - j + 1);

		}
		return res;
	}
};