
#include <bits/stdc++.h>

class Solution {
public:
	int longestSubarray(std::vector<int>& nums) {
		int res = 0, start = 0, zero = 0;
		for (int i = 0; i < nums.size(); i++) {
			zero += (nums[i] == 0);
			while(zero > 1) {
				zero -= (nums[start] == 0);
				start++;
			}
			res = std::max(res, i - start);
		}
		return res;
	}
};