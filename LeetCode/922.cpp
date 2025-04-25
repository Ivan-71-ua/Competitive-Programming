#include <bits/stdc++.h>


class Solution {
public:
	std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
		std::vector<int> res(nums.size());
		int even = 0;
		int odd = 1;
		for (int i = 0; i < nums.size(); i++) {
			if(nums[i] & 1) {
				res[odd] = nums[i];
				odd += 2;
			} else {
				res[even] = nums[i];
				even += 2;
			}
		}
		return res;
	}
};