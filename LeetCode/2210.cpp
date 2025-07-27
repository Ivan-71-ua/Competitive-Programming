#include <bits/stdc++.h>

class Solution {
public:
	int countHillValley(std::vector<int>& nums) {
		int res = 0, n = nums.size();
		std::vector<int> unic;
		unic.reserve(n);
		unic.push_back(nums[0]);
		for (int i = 1; i < n; i++) {
			if(nums[i] != nums[i - 1]) {
				unic.push_back(nums[i]);
			}
		}
		for (int i = 1; i < unic.size() - 1; i++) {
			if(unic[i - 1] > unic[i] && unic[i] < unic[i + 1])
				res++;
			if(unic[i - 1] < unic[i] && unic[i] > unic[i + 1])
				res++;
		}
		return res;
	}
};